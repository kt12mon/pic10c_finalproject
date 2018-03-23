# pic10c_finalproject
Monte Carlo Simulation of Monopoly:

Class Concepts used:
STL Containers: Unordered set for efficient data storage, access and editting.

Iterators: to navigate through STL Container

Algorithms: Created own custom algorithms for specific needs. Used recursion and exit conditions.

Official rules <http://www.hasbro.com/common/instruct/00009.pdf>

I have implemented the basic rules of Monopoly with a few exceptions:

1. We are not tracking money as there is no chance model that can be used to determine a player's choice of buying property, making bids, etc. 

2. Jail is simulated with the rules of jail, however, there is no way to model a player's choice to pay the fee to get out of jail. We will thus assume a player will never pay to get out of jail and will stay until they are kicked out or fulfill the doubles condition. This is a sound assumption because it is established strategy to try to stay in jail as long as possible as the game further progresses.

3. Chance and Community decks are drawn on a uniform chance model even though the rules state a drawn card goes back to the bottom of the deck. In a future implementation: a seperate chance/community class should be established to define a set order of cards and keep track of when the entire deck is drawn so a reshuffle can be executed. 

This project's main components are concerned with 2 objectives: accuracy of simulation and runtime efficiency. Accuracy of simulation are described by the rules above. As for runtime efficiency, I have implemented the simulation, data storage, and data writing as close to O(n) as possible. Simulation is ran at O(n) via a for loop and number of iterations. Data collection is ran at O(1) time due to the use of the closest thing to a hash map, an unordered set. The process is described in the classes below.

Dice_roll class:
Variables: 
total_roll - keeps track of number rolled
doubles_rolled - keeps track if a double was rolled

Functions:
Dice_roll() - default constructor;
roll() - assigns the total_roll from 2 randomly generated numbers. Also assignes whether or not a doubles was rolled
get_total() - accessor to get total_roll
get_doubles_status - accessor to get doubles_rolled

Player class:
Variables:
position - tracks position on board that player is on
in_jail - bool to track if player is in jail. Important for rules of jail since a player can be on the jail space but not in jail.
double_count - tracks number of consecutive doubles player has rolled. Important for sending player to jail for rolling 3 consecutive doubles.
doubles_attempted - tracks number of doubles attempted to roll while in jail. After 3, player is no longer in jail.
game_record - unordered map that keeps track of spaces landed on by player. Records space number, space name, and times landed on.

Functions:
Player() - default constructor. initializes all values to defaul 0s.
get_jail_status() - accessor to return in_jail
get_position() - accessor to return position
init_record() - initializes a clear player record. Requires monopolyboard.txt in directory
move_n() - changes player position
in_jail_rules() - function used to dictate how a player acts in jail
roll_doubles_check() - function used to see if a player who rolled doubles, gets sent to jail.
update_record() - updates record of player position in game_record
print_table() - prints table to console
export_table() - exports table as a txt file with tab as delimiter.

Sample output:
1. "Go" was landed on 1 times.
2. "Mediterranean_Avenue" was landed on 3 times.
3. "Community_Chest" was landed on 0 times.
4. "Baltic_Avenue" was landed on 0 times.
5. "Income_Tax" was landed on 3 times.
6. "Reading_Railroad" was landed on 4 times.
7. "Oriental_Avenue" was landed on 2 times.
8. "Chance" was landed on 1 times.
9. "Vermont_Avenue" was landed on 0 times.
10. "Connecticut_Avenue" was landed on 4 times.
11. "Jail" was landed on 4 times.
12. "St._Charles_Place" was landed on 3 times.
13. "Electric_Company" was landed on 2 times.
14. "States_Avenue" was landed on 1 times.
15. "Virginia_Avenue" was landed on 1 times.
16. "Pennsylvania_Railroad" was landed on 2 times.
17. "St._James_Place" was landed on 3 times.
18. "Community_Chest" was landed on 2 times.
19. "Tennessee_Avenue" was landed on 4 times.
20. "New_York_Avenue" was landed on 0 times.
21. "Free_Parking" was landed on 4 times.
22. "Kentucky_Avenue" was landed on 1 times.
23. "Chance" was landed on 2 times.
24. "Indiana_Avenue" was landed on 3 times.
25. "Illinois_Avenue" was landed on 7 times.
26. "B&O_Railroad" was landed on 0 times.
27. "Atlantic_Avenue" was landed on 0 times.
28. "Ventnor_Avenue" was landed on 4 times.
29. "Water_Works" was landed on 2 times.
30. "Marvin_Gardens" was landed on 3 times.
31. "Go_to_jail" was landed on 0 times.
32. "Pacific_Avenue" was landed on 2 times.
33. "North_Carolina_Avenue" was landed on 3 times.
34. "Community_Chest" was landed on 2 times.
35. "Pennsylvania_Avenue" was landed on 3 times.
36. "Short_Line_Railroad" was landed on 1 times.
37. "Chance" was landed on 2 times.
38. "Park_Place" was landed on 3 times.
39. "Luxury_Tax" was landed on 2 times.
40. "Boardwalk" was landed on 2 times.