---
title: "Simple Flash Card"
date: 2014-11-14
---
![Simple Flashcard Screenshot](/img/flashcard.jpg)One of my goals is to get my
A+ certification this coming Spring (or sooner, if possible). As I have been
going through my Computer Hardware Maintenance Textbook, I am discovering that
there are plenty of things I need to memorize – general facts that I need to
know. For some of the legacy hardware I am required to know about, I have
already memorized these things (e.g. I know that 3.5” floppy disks hold 1.44 MB
if formatted with high density formatting) because I used to use a lot of this
kind of equipment. But there are some things I don’t know so well, like current
CPU and Socket types.

To that end, I decided that it would be helpful to write a program that would
give me flashcards to drill me on some of these things. So, I create a text file
with the question, separated by a | character, followed by the answer (each set
of questions and answers is on a newline). The program will flash a question at
me, I see if I know the answer, then I push a button and recieve the answer. The
computer then asks me if I got it right or wrong. Based on that, it will ensure
that I get to see that card again – meaning that if I get every other one right
but one question, it will keep showing me that one until I get it right (before
restarting the deck, that is). At the end of my file, I have on a newline.

Once I have done the question, it will start the timer (using the value I gave
it upon starting). Once a minute has been reached, the answer is removed from
the screen. At the end of the designated time, it will ding at me to get my
attention from whatever I am doing, and ask me another question.

[Here is the actual source code](/files/flashcard.c), for those that are
interested.
