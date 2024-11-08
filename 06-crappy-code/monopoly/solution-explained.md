# Monopoly: Solution

## Code Smells Included
1. Magic Numbers: Unexplained numbers scattered throughout the code.
2. Comments for Code: Redundant comments explaining obvious code.
3. Temporary Field: Unused fields in classes initialized only under specific conditions.
4. Message Chains: Long chains of method calls to access data.
5. Inconsistent Naming: Variables and methods with vague or inconsistent names.
6. Shotgun Surgery: Minor changes require updating many places across classes.
7. Middle Man: Classes that simply pass calls to other classes.
8. Data Clumps: Groups of variables often passed together.
9. Large Class: A class that takes on too much functionality.
10. Excessive Use of if-else: Instead of using polymorphism or encapsulating logic.

## Explanation of Refactorings
1. Removed Magic Numbers: Introduced constants or properties for hardcoded values.
2. Removed Redundant Comments: Replaced unnecessary comments with meaningful variable names.
3. Removed Temporary Fields: Initialized jailTurn only if necessary.
4. Eliminated Message Chains: Avoided multiple levels of access by centralizing actions.
5. Improved Naming: Used clear names to replace inconsistent or vague ones.
6. Eliminated Shotgun Surgery: Adjusted property rent directly instead of in multiple places.
7. Removed Middle Man: Simplified MonopolyGame to avoid being a mere delegate for actions.
8. Removed Data Clumps: Encapsulated data fields into cohesive classes.
9. Divided Large Class: Distributed Property and Player responsibilities across dedicated methods.
10. Removed Excessive If-Else: Encapsulated behaviors in methods, reducing reliance on conditional chains.