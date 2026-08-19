---
title: "The Matrix"
date: 2014-10-16
---
![Matrix Screenshot](/img/matrix.jpg)So, I decided that I need my own Matrix
Screen. Once upon a time, I downloaded a pretty good screen saver of the Matrix
effect. But that was close to a decade ago – and I have no idea where I got it
from or where my copy of it went. Therefore, I need a new one.

I realized that with my current coding skills, I could probably write my own in
C. It is simply a matter of writing the letters into an array, updating their
positions, and printing it out to the screen. The trouble with doing this is
that the standard C libraries do not seem to come with ANYTHING to enable me to
over-write what has been written on the screen. At best, I can overwrite a
single line of text by using the escape. I could also use:system(“cls”);.
However, that is – at best – not portable and – at worst – creates a flashing
screen that would drive anyone watching it nuts. Actually, the above mentioned
method was the method I have used in the past as I have experimented with ASCII
graphics.

The solution was to use the [PdCurses](http://pdcurses.sourceforge.net/) library
(or NCurses when I was compiling it on Linux). This allowed me to implement
basic color as well as to redraw the screen without it flashing like some kind
of firefight.

Without going into great detail of the specifics of using a curses library, one
of the key features I used for this program is the “mvprintw” function. Unlike
“printf”, this allows me to move the cursor to a location on screen (in the
format Y,X if memory serves me). This means that I can go anywhere on screen
(within my console window) and overwrite any character anywhere. So, with the
help of curses, I was well on my way to making my own matrix-style screen.

After studying a few different videos featuring this scrolling effect on
YouTube, I concluded that the text can flow downwards at the same speed. I also
decided that it would look best to make the first digit white. Furthermore, I
also realized that to be truly authentic I ought to have some of the letters
randomly change while they are on-screen. Finally, All of the text starts at the
top – so that is easy – and flows down.

What I did was to create an array the width and the height of my terminal window
(a feat that curses helped with again). Then, using “rand()”, I selected a
random starting point along the X-axis and then place a random character into
that array. Additionally, I put a random string length (for the purposes of this
program, I call the falling lines of numbers “strings”) and a string duration.
The string number dictates how long the string will be up to a certain minimum
value and the duration dictates how long the string will last for.

So then, each cycle through the array, any strings that have a length remaining
value greater than 0 AND have a blank space below them (this is how it knows if
this “length remaining” value has already been read or not) and has a time
remaining value less than the total duration (those are stored as two separate
values) creates a new random character on the line immediately below it. This
new character inherits that duration value from the previous character and the
length (or length_remaining) value decremented by one.

As the program inspects the array, there is a random chance of changing the
character stored in the array. When the loop finds a character whose
time_remaining value is zero, it erases it and all its associated data.

Once the array has been read and processed, we then need to print out the array.
Using mvprintw, this is pretty straight forward. I also use curses to change the
leading character of the string (the newest created) to white. It does this by
looking at the duration time and its time remaining values to see if it is brand
new or not. Then we refresh the screen (rapidly updating in curses without a
refresh seems to lead to no output, even though using mvprintw to alter a
character here and there but not continuously seems to work without refreshing
under certain circumstances) and delay for a set amount of time. And the process
begins all over again.

Here is the actual source code (note: source code appears to have been lost),
for those that are interested.

The Matrix Franchise are owned by Warner Brothers. No Copyright Infringement is
intended.
