# Nato translator

Translate words into NATO

| Words  |         |           |         |        |           |
| ------ | ------- | --------- | ------- | ------ | --------- |
| "Alfa" | "Bravo" | "Charlie" | "Delta" | "Echo" | "Foxtrot" |
| "Golf" | "Hotel" | "India" | "Juliett" | "Kilo" | "Lima" |
| "Mike" | "November" | "Oscar" | "Papa" | "Quebec" | "Romeo" |
| "Sierra" | "Tango" | "Uniform" | "Victor" | "Whiskey" | "Xray" |
| "Yankee" | "Zulu" | | | |

Examples:

1. Turn text into nato:

```
nato_translator/nato.c
./a.out nato_translators/text.txt
```

Result:

```Papa Romeo India Mike Alfa Romeo Yankee Foxtrot Romeo Oscar November Tango Echo November Delta Whiskey Echo Bravo Foxtrot Romeo Alfa Mike Echo Whiskey Oscar Romeo Kilo Sierra Romeo Echo Alfa Charlie Tango Alfa November Golf Uniform Lima Alfa Romeo Victor Uniform Echo```

2. Search for nato words into random words:

```
cc nato_translator/word_parse_file.c
./a.out nato_translator/text2.txt
```

Result: "HELLO"

3. Identify nato words and turn them into letters:

```
cc nato_translator/word_parse.c
./a.out
```

Result:

```
Enter NATO text: tango echo sierra tango
TEST
```

---

1. Contents of file `nato_translators/text.txt`:

```Primary frontend web frameworks: React, Angular, Vue```

2. Contents of file `nato_translator/text2.txt`:

```
Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque hotel faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu echo. Ad litora torquent per conubia nostra inceptos himenaeos.

Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque lima faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.

Lorem lima ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.

Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.

Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti oscar sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.
```