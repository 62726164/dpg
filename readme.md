# DPG - Deterministic Password Generator

DPG is a deterministic password generator that does not store data or keep state. Its output is based purely on user input.

## To Build C++ executable

```bash
$ cd c++ && make
```

## To Build Java jar

```bash
$ cd java && ./build.sh
```

## To Run Python, Java or C++ version

```bash
$ python dpg.py
$ java -jar dpg.jar
$ dpg "The sentence" word
```

## Usage Recommendations

  * Use the same sentence everywhere. Commit it to memory.
  * Use a different word for different sites. Be consistent with case (e.g. google, facebook, twitter, etc.)
  * If you need to change all of your passwords, change the sentence.
  * If you need to change one site password, change the word.

## Screenshot of Java GUI implementation

  ![Screenshot](java/pics/dpg.png?raw=true)

## Why traditional password managers are flawed

Moved to [blog]() post.

## Notes

  * DPG is based on my earlier SHA1_Pass software in 2009.
  * The C++ implementation is intended for testing and validation only.
