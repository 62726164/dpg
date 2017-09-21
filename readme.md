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

I wrote DPG because I sometimes work in highly audited/regulated environments and I needed a way to recall dozens of complex passwords that change frequently and I disagree with the core concepts of most traditional password management software in use today. I believe that their approach is fundamentally flawed.

If after reading this you still wish to use a traditional password manager, I suggest that you put your passwords into a plain text file and symmetrically encrypt it with [GnuPG](https://www.gnupg.org/) or use [Password Safe](https://pwsafe.org/).

OK, onto my argument. I disagree with two common concepts used by traditional password managers:

  1. Password Storage
  2. Remote Systems & Web Browser Integration

When passwords are stored, they must be encrypted and then retrieved later when needed. Storage, of any type, is a burden. Users are required to backup stored passwords and synchronize them across devices and implement measures to protect the stored passwords or at least log access to the stored passwords for audit purposes. Unless backups occur regularly, if the encrypted password file becomes corrupt or is deleted, then all the passwords are lost.

Users must also devise a "master password" to retrieve the encrypted passwords stored by the password management software. This "master password" is a weak point. If the "master password" is exposed, or there is a slight possibility of potential exposure, confidence in the passwords are lost.

My other concern with password storage is proper encryption. Are you sure the encryption used to store the passwords is implemented correctly? Has the encryption been externally validated? Some password management software is closed-source and proprietary and cannot be verified or validated in any way. Encryption is hard. [Even expert developers with many years of experience make mistakes](http://www.daemonology.net/blog/2011-01-18-tarsnap-critical-security-bug.html) that render encryption weak or in some cases almost useless. 

Now, for my second disagreement with traditional password managers. I believe that password management should only occur locally on end use devices, not on remote systems and not in the client web browser.

Remote systems are outside the user's control and thus cannot be trusted with password management. These systems may not be available when needed and may not be storing or transmitting passwords correctly. Externally, the systems may seem correct (https, etc.) but behind the scenes, no one really knows what's going on, how the passwords are being transmitted, generated, stored, or who has access to them. And, many popular cloud-based password managers have reported multiple security breaches. Here are a few examples: [1](http://www.darkreading.com/attacks-breaches/onelogin-breach-reignites-concerns-over-password-managers/d/d-id/1329034), [2](https://arstechnica.com/security/2017/03/potent-lastpass-exploit-underscores-the-dark-side-of-password-managers/), [3](https://www.wired.com/2015/06/hack-brief-password-manager-lastpass-got-breached-hard/).

Web browsers today have "everything but the kitchen sink" capabilities built-in and are becoming more and more complex each year. They are turning into whole platforms that have browser plug-ins and extensions for every possible need known to man. While many of these add-ons are handy and useful, you should not trust these add-ons with password management. Browsers are just too complex and have far too much going on to trust them with password management.

DPG addresses these flaws. Here are the key design concepts.

  * DPG does not store passwords, it only generates passwords as needed. Because of this, the need to backup, synchronize and properly encrypt passwords is removed. This eliminates the weak point of having a "master password" that immediately unlocks all of the other passwords. There is nothing to audit access to and nothing to become lost, stolen or corrupt. No storage means you have none of the problems associated with password management storage.

  * DPG only runs locally on end-use devices. It is a stand-alone application that does not rely on remote systems, and it is not integrated into web browsers along with numerous other browser "add-ons". 

  * DPG is open-source and the passwords it generates can be verified and validated by other implementations.

Password managers are important, but they shouldn't be difficult to deal with or untrustworthy. DPG removes many of the issues that I have experienced with traditional password management software. I hope you find it as useful as I have over the years.

## Notes

  * DPG is based on my earlier SHA1_Pass software in 2009.
  * The C++ implementation is intended for testing and validation only.

