import os
import sys
import fileinput

dic = { 
    " u ":" u~",
    " U ":" U~",
    " k ":" k~",
    " K ":" K~",
    " o ":" o~",
    " O ":" O~",
    " s ":" s~",
    " S ":" S~",
    " v ":" v~",
    " V ":" V~",
    " z ":" z~",
    " Z ":" Z~", 
    " a ":" a~", 
    " A ":" A~",
    " i ":" i~",
    " I ":" I~",
    "~u ":"~u~",
    "~k ":"~k~",
    "~o ":"~o~",
    "~s ":"~s~",
    "~v ":"~v~",
    "~z ":"~z~",
    "~a ":"~a~",
    "~i ":"~i~"
}

filesToReplace = ["./cile.tex", "data.tex", "mechanika.tex", "pcb.tex", "prilohy.tex", "reseni.tex", "teorie.tex", "uvod.tex", "zaver.tex"]

for fileToSearch in filesToReplace:
    with open(os.path.join(sys.path[0], fileToSearch), 'r', encoding='utf-8') as file :
        filedata = file.read()

    # Replace the target string
    for word, init in dic.items():
        filedata = filedata.replace(word, init)

    # Write the file out again
    with open(os.path.join(sys.path[0], fileToSearch), 'w', encoding='utf-8') as file:
        file.write(filedata)