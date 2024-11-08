# Solution

## Code Smells to be identified
1. Data Class: Simple data-only class Monk.
2. God Class: MonasteryManager manages too many responsibilities.
3. Feature Envy: External methods access data from Monk.
4. Duplicated Code: Repeating similar logic in multiple functions.
5. Long Method: Overly long manageBrewery.
6. Primitive Obsession: Using string and int for manageInventory.
7. Speculative Generality: Unused, over-engineered code.
8. Inappropriate Intimacy: MonasteryManager accessing internal details of Monk class.
9. Switch Statements: Multiple conditionals for monk roles instead of polymorphism.
10. Lazy Class: Library class with minimal functionality.

## Explanation of Refactorings
1. Single Responsibility: Separated classes for Monastery, Brewery, Inventory, and Duty.
2. Eliminated God Class: Distributed responsibilities across classes.
3. Removed Feature Envy: Moved printInfo and isElder into Monk.
4. Removed Duplicate Code: Reused printInfo and isElder.
5. Simplified Long Method: Reduced complexity in brewBeer.
6. Avoided Primitive Obsession: Added InventoryItem class.
7. Eliminated Speculative Generality: Removed unused code like monitorAirQuality.
8. Replaced Inappropriate Intimacy: Encapsulated monk role logic with Duty.
9. Replaced Switch Statements: Used polymorphism with Duty classes.
10. Removed Lazy Class: Repurposed Library or avoided if unnecessary.