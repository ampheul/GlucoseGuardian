# Glucose Guardian: The Artificial Pancreas

This is a software application which emulates the function of a human pancreas.
The Glucose Guardian takes in insulin readings from an external device and sends an insulin dosage
as a result. It can also store patient information to create reports and respond to emergency situations.


# Authors

Claire Dong
Graeme Brabers
Naeem Budhwani
Thomas Vandeveen
Veronica Witzig


# How to build Glucose Guardian

You will need 3 terminals for the full functionality of Glucose Guardian. 
	- 1 terminal will be used for the monitor
		- Monitor is the glucose monitor that provides blood glucose readings to the pi
	- 1 terminal will be used for running main 
		- Main is the UI for user interaction with the artifical pancreas
	- 1 terminal will be used for the listener
		- Listener is the insulin pump that waits for information from the pi and dispenses insulin

make all 

Once the project has been built, you can run the program by executing the _____ file. 

# How to run acceptance tests


For the completed tickets, here are the tests to run:

	Error message will be displayed if tests fail
	Nothing will be displayed if tests pass 
	(In some cases, "Invalid glucose reading" prints as it should) 

# Medication  Calculator Tests
g++ HormoneDose.cpp MedicationCalculator.cpp MedicationCalculatorTestAge.cpp -o AgeTest
./AgeTest

g++ HormoneDose.cpp MedicationCalculator.cpp MedicationCalculatorTestGluc.cpp -o GlucTest
./GlucTest

g++ HormoneDose.cpp MedicationCalculator.cpp MedicationCalculatorTestExercise.cpp -o ExerciseTest
./ExerciseTest

g++ HormoneDose.cpp MedicationCalculator.cpp MedicationCalculatorTestMeal.cpp -o MealTest
./MealTest

Please run this one at 10pm at night as it takes into consideration the current time and compares it to a user defined bed time:
g++ HormoneDose.cpp MedicationCalculator.cpp MedicationCalculatorTestSleep.cpp -o SleepTest
./SleepTest

# Account Tests
The password for the patient account is password123
The password for the guest account is guest123
g++ Account.cpp AccountTestHarnesses.cpp

# Output Test

