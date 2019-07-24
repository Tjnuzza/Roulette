# Roulette
Roulette simulation programmed in C++ and played through a command line.

## Overview
This isn't really an object-oriented program, in fact there are no classes written for it specifically.
Instead it's really a structured program, using a collection of functions within a while loop.
All game information exists as a primitive that gets passed around as function inputs and outputs.

## How to play
It is a Euro-style roulette wheel with no double zero option.
You can bet on a range of options, but you can't place any bets once the wheel starts spinning.
Additionally, you can't place custom bets.

## How it works
The program initializes all the required variables and then enters a while loop.
The loop runs through the menu, and unless the user indicates they want to quit, runs through the loop of each method.
It has methods for acquiring all necessary information from the user: bet amount, what to bet on, and a specific number if appropriate.
After spinning, it announces the results. If the user won, it also rewards money as appropriate.

## Future plans
For now, everything appears to be working as it should. I've fixed the glitch where invalid inputs cause the program to get stuck in an infinite loop.
I might someday remake it in C# so I can include it in a suite of casino games with the blackjack program. That might be a webpage implented with ASP.NET and JavaScript.