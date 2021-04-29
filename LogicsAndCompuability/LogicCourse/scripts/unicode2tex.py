#! /usr/bin/python
import click

""" Small utility to convert unicode logic to tex """

tex_map = {
    '∨': '\\lor',
    '∧': '\\land',
    '⇒': '\\Rightarrow',
    '⇔': '\\Leftrightarrow',
    '¬': '\\lnot ',
    '{': '$\{',
    '}': '\}$'
}


def rawtxt2tex(sentence):
    for key, val in tex_map.items():
        sentence = sentence.replace(key, val)
    return sentence


def while_input():
    while True:
        str_unicode = input("Enter unicode string: ")
        if str_unicode == 'exit':
            break
        str_tex = rawtxt2tex(str_unicode)
        print(str_tex)


def file2tex(filename):
    with open(filename, 'r') as file:
        str_unicode = file.read()
        str_tex = rawtxt2tex(str_unicode)
        print(str_tex)


@click.command()
@click.argument('filename', type=click.Path(), default='')
@click.option('--whileinput', default=False)
def main(filename, whileinput):
    if whileinput:
        while_input()
    else:
        file2tex(filename)


if __name__ == '__main__':
    main()
