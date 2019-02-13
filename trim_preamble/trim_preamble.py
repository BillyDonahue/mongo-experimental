#!/usr/bin/env python3

import sys
import re

for fn in sys.argv[1:]:
    out_lines = []
    lines = [s.rstrip('\n') for s in open(fn, "rt")]
    base = re.sub('.*/', '', fn)
    rel1 = re.sub('src/', '', fn)
    rel2 = re.sub('src/mongo/', '', fn)
    patterns = [
        re.compile('^$'),
        re.compile('^// *(@file)? *({:s}|{:s}|{:s})$'.format(
            re.escape(fn),
            re.escape(base),
            re.escape(rel1),
            re.escape(rel2))),
        re.compile('^/\*\* *(@file)? *({:s}|{:s}|{:s}) *\*/$'.format(
            re.escape(fn),
            re.escape(base),
            re.escape(rel1),
            re.escape(rel2)))
    ]

    i = 0
    for line in lines:
        i = i + 1
        match = False
        for pat in patterns:
            if re.match(pat, line):
                match = True
                break
        if match:
            continue
        out_lines.append(line)
        if not re.match('^/\*\*$', line):
            # interesting header line to be reviewed manually!
            print("{:s}:{:d}:[{:s}]".format(fn, i, line))
        break
    out_lines.extend(lines[i:])
    fout = open(fn, "wt")
    fout.writelines([s + "\n" for s in out_lines])
