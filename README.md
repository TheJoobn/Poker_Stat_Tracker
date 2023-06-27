# Fun Poker Program 
---------------------------------------------
          FIXME:
 - Undo process only half works - needs testing, only adjusts numbers but not players removed or other major changes.
 - first hand starts at sb
 - order possibly gets messed up after a hand or so

---------------------------------------------
          NEEDED IMPROVEMENTS:
- XXX Input starting amount for sit and go 
- XXX Ability to enter a string of multiple commands or some other way to increase operation speed.
- XXX input one or two digit number such as 5, 10, or 40 and convert it to millions
- add chips calculations? not sure if useful yet.
- after so many hands, single out users with very high play percentages in a category and indicate player type
- add function to reset table or add people to table.
- input what position user is along with position of BB

---------------------------------------------
          FUTURE IMPROVMENT IDEAS:
- add input for hand combinations along with suggestions based on my playstyle graph and a compilation of pro graphs.
- Could track playstyle and give suggestions.
- Give suggestions based on the playstyles of others at the table.
- Give suggestions based on a chosen playstyle: Aggro, conservative, Precision, etc...
- Create a better visual to better visualize the table and actions.
- create audible or visual way of input control
- keep long term records of stats and give recomendations based on them.
- keep records of tournaments/sit and go wins and losses along with placement posisition and possibly info for last 3-5 hands.
- take inputs for people left in multi table setting, give recomendations based on current variables
- keep track of BB multiplier, especially convenient for multi table
- keep track of BB and give advice based on that with ratio of BB multiplier
- create records and profiles for players you play against often, will help remember their playstyle

---------------------------------------------
---------------------------------------------
---------------------------------------------
          Overview:
**Functions and Actions:**

          Poker Version 1: 6/25/23
- C - Call                     
- R - Raise                     
- F - Fold
                       
- B - Set current player as Big Blind     
- S - Set current player as Small Blind   
- N - Set current player's Name
- M - Set current player as Yourself
  
- V - Skip current player's turn    FIXME<----------------------- 
- G - Go back to last player's turn          FIXME<-----------------------
  
- U - Undo the last move that was made           FIXME<-----------------------
- X - Eliminate current player from the game

---------------------------------------------
             Poker Version 2:  6/27/23

- I setup the D key with a "enter" hotkey through software.
- If more than one action character is entered at a time, they will be split and applied to each player in order.

- E - if first character is e, all action characters following will be applied to current player
- A - Lets user enter a number to be converted to milllions, is set as all users starting chip amount.

- "-" Ends the game.
- "=" Starts the game again.
---------------------------------------------














