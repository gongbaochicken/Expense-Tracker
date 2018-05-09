# Expense-Tracker
#### Developers: Zhuo Jia(gongbaochicken), Jingxiong Huang, Guoshan Liu
#### [source code stopped maintained, as this is just a final demo.]

Expense Tracker is a user-friendly software for personal financial management. Features within Expense Tracker are well integrated. These main functions and features include balance tracking, category labeling, search bar, data visualization and smart shopping list. To enhance user experience, Expense Tracker can generate weekly and monthly spending reports with QR codes that can be easily stored and shared.

 ![image](https://github.com/gongbaochicken/Expense-Tracker/raw/master/showcase_img/logo.bmp)
 
This software is a course project for ECE 551:  Program, Data Structure and Algorithm in C++. For this reason, Expense Tracker is implemented in C++. The GUI is developed using Qt Creator integrated development environment (IDE) with standard libraries.

# FEATURES & MERITS
### Balance Tracking
 ![image](https://github.com/gongbaochicken/Expense-Tracker/raw/master/showcase_img/1.png)
+ Set user’s monthly expense target with ease, and the budget will automatically reset to zero at the beginning of each month. + Distinct monitor bar shows the percentage of up-to-date amount of expenditure over current month’s budget, as a reminder to save money.
+ Access payments recorded on a certain day, by clicking on the date on calendar.

### Category Labeling
 ![image](https://github.com/gongbaochicken/Expense-Tracker/raw/master/showcase_img/11.bmp)
+ Specify amount and label category of each income and expense, in order to better classify these items.
+ What if the user cannot find an appropriate category in the default list? Feel free to create a new option! 
+ Store all financial data in a CSV file. 

### Search Bar 
 ![image](https://github.com/gongbaochicken/Expense-Tracker/raw/master/showcase_img/2.png)
+ This feature provides users with a convenient way to locate and view specific items of expense and income. 
+ By searching for category or item name, users will see the transaction details they need displayed on the detail table.

### Data Visualization 
 ![image](https://github.com/gongbaochicken/Expense-Tracker/raw/master/showcase_img/3.png)
+ Display a pie chart and a line chart displaying the user’s transaction data of the selected date. 
+ Users have multiple range options for transaction visualization, such as the transactions within the last 7 days, 30 days or the whole year. Another choice is to define a customized range to search for their transaction information.
+ After the range is chosen, a line chart and a pie chart will be shown correspondingly on the right side of the board, enhancing users’ visual experience. The line chart shows the amount of expense of each day, while the pie chart presents the data in various categories, as well as the total expense, of the selected dates.

###Smart Shopping List
 ![image](https://github.com/gongbaochicken/Expense-Tracker/raw/master/showcase_img/4.bmp)
+ Add items to the shopping list as a reminder. Users can remove the items after purchasing them or when they change their minds.
+ Meanwhile, users can optionally choose whether to add predictive cost of these items to the original budget. If they wish to do so, Expense Tracker will update the budget and percentage monitor bar promptly. 

###Brief Report in QR Code
 ![image](https://github.com/gongbaochicken/Expense-Tracker/raw/master/showcase_img/5.bmp)
+ Generate a QR code, which contains a brief report of users’ expense information, including specific items and total cost. 
+ QR code can be easily saved and shared to the people who desire these pieces of information. 

