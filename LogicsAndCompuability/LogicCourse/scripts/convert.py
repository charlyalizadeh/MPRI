#! /usr/bin/python

""" Small utility to convert XML proof to tex """

import sys
import xml.etree.ElementTree as ET

tex_map = {
    '|': '\\lor',
    '&': '\\land',
    '=>': '\\Rightarrow',
    '<=>': '\\Leftrightarrow',
    '~': '\\lnot '
}


def rawtxt_to_tex(sentence):
    for key, val in tex_map.items():
        sentence = sentence.replace(key, val)
    return sentence


filename = sys.argv[1]
tree = ET.parse(filename)
proof_xml = tree.getroot()
premises = []
proofs = []
indent = 1
for step in proof_xml:
    sentence = rawtxt_to_tex(step[1].text)
    justification = step[2].text
    ispremise = justification == 'Premise'
    indent += (justification == 'Assumption') - (justification == 'Implication Introduction')
    for i, antecedent in enumerate(step[3:]):
        if i == 0:
            justification += ' ('
        justification += antecedent.text
        if i < len(step) - 4:
            justification += ','
        else:
            justification += ')'
    if ispremise:
        premises.append([sentence, justification, indent])
    else:
        proofs.append([sentence, justification, indent])

text_tex = "$$\n\\begin{fitch}\n"
for i, p in enumerate(premises):
    if i == len(premises) - 1:
        text_tex += '\\fj '
    else:
        text_tex += '\\fa '
    text_tex += p[0] + ' & ' + p[1] + '\\\\\n'

for i, p in enumerate(proofs):
    text_tex += '\\fa ' * p[2] + p[0] + ' & ' + p[1] + '\\\\\n'


text_tex += "\\end{fitch}\n$$"
print(text_tex)
