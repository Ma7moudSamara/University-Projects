// ASSIGNMENT 3        1191602        MAHMOUD SAMARA     COMP231      DR.HAFEZ BARGHOUTHI          SEC2

import java.util.Date;
import java.util.ArrayList;

public class TestEmployee {

	@SuppressWarnings("deprecation")
	public static void main(String[] args) {
		System.out.println(
				"                *************************** Welcome to the program *************************** \n ");
		System.out.println(
				" <<.........This program shows the explain of a factory that has several workers and how it works from shifts(day and night) , earnings , different informations for the workers and the work for each worker ........ >> \n ");
		System.out.println(
				"                           ####################### Palestinian Dairy Factory  ####################### \n ");

		// First we need to create the array list to store employee objects for
		// different subclasses.
		ArrayList<Employee> EmployeesInformation = new ArrayList<>();

		// Filling the Informations for the Production Worker by using ArrayList.
		Address productionAddress1 = new Address("Sofyan Street", "Nablus", "Beit Imreen", 103143);
		EmployeesInformation
				.add(new ProductionWorker("Ali", "112-D", new Date("3/10/2001"), productionAddress1, 1, 25, 209));

		// Filling the Informations for the Production Worker by using ArrayList.
		Address productionAddress2 = new Address("Irsal Street", "Ramalla", "Burqa", 662001);
		EmployeesInformation
				.add(new ProductionWorker("Safaa", "314-B", new Date("4/14/2014"), productionAddress2, 2, 18, 190));

		// Filling the Informations for the Production Worker by using ArrayList.
		Address productionAddress3 = new Address("Faisal Street", "Haifa", "Asira", 65812734);
		EmployeesInformation
				.add(new ProductionWorker("Qays", "872-F", new Date("7/22/2017"), productionAddress3, 3, 12, 250));

		// Filling the Informations for the ShiftSupervisor by using ArrayList.
		Address ShiftSupervivorAddress1 = new Address("Rafidya Street", "Hebron", "Tarqoomia", 19102002);
		EmployeesInformation.add(new ShiftSupervisor("Saeed", "512-M", new Date("6/6/2008"), ShiftSupervivorAddress1,
				1400, 650, 300, 260));

		// Filling the Informations for the ShiftSupervisor by using ArrayList.
		Address ShiftSupervivorAddress2 = new Address("Maka Street", "Amman", "Sabastiya", 1622468);
		EmployeesInformation.add(new ShiftSupervisor("Mahmoud", "182-E", new Date("10/26/2018"),
				ShiftSupervivorAddress2, 2650, 520, 360, -480));

		// Filling the Informations for the ShiftSupervisor by using ArrayList.
		Address ShiftSupervivorAddress3 = new Address("Madina Street", "TulKarim", "Sanoor", 2578924);
		EmployeesInformation.add(new ShiftSupervisor("Osama", "167-A", new Date("8/26/2016"), ShiftSupervivorAddress3,
				-4000, 520, -240, -220));

		// Filling the Informations for the TeamLeader by using ArrayList.
		Address TeamLeaderAddress1 = new Address("Center Street", "Jenin", "Sanoor", 986532);
		EmployeesInformation.add(
				new TeamLeader("Ghassan", "614-F", new Date("8/6/2012"), TeamLeaderAddress1, 1, 50, 190, 1680, 60, 50));

		// Filling the Informations for the TeamLeader by using ArrayList.
		Address TeamLeaderAddress2 = new Address("KingHussein Street", "Jericho", "Aqraba", 4563298);
		EmployeesInformation.add(new TeamLeader("Laith", "986-H", new Date("12/11/2019"), TeamLeaderAddress2, 2, 10.5,
				165, 2200, 80, 96));

		Address TeamLeaderAddress3 = new Address("Quds Street", "Jericho", "Yaseed", 65973152);
		EmployeesInformation.add(
				new TeamLeader("Ayoub", "264-L", new Date("4/2/2020"), TeamLeaderAddress3, 3, 15, 200, -1800, 80, 100));

		double TotalSalaryAllEmployees = 0.0;

		// I added an extra for loop to calculate the total salary for all Employees
		// that they
		// written in the Array List also print the result and before that print the
		// informations for all Employees

		for (int Beginning = 0; Beginning < EmployeesInformation.size(); Beginning++) {

			// checking if the current chosen employee is Instance of Production Worker if
			// yes we will make the casting for it to use in different situations
			if (EmployeesInformation.get(Beginning) instanceof ProductionWorker)

				TotalSalaryAllEmployees += ((ProductionWorker) EmployeesInformation.get(Beginning)).getTotalSalary();

			// checking if the current chosen employee is Instance of ShiftSupervisor if yes
			// we will make the casting for it to use in different situations
			else if (EmployeesInformation.get(Beginning) instanceof ShiftSupervisor)

				TotalSalaryAllEmployees += ((ShiftSupervisor) EmployeesInformation.get(Beginning)).getTotalSalary();

			// checking if the current chosen employee is Instance of TeamLeader if yes we
			// will make the casting for it to use in different situations
			else if (EmployeesInformation.get(Beginning) instanceof TeamLeader)

				TotalSalaryAllEmployees += ((TeamLeader) EmployeesInformation.get(Beginning)).getTotalSalary();

			// checking if the current chosen employee is Instance of ShiftSupervisor if yes
			// we will make the casting for it to use in different situations

			if (EmployeesInformation.get(Beginning) instanceof ShiftSupervisor) {
				// Printing ShiftSupervisor sentence for ShiftSupervisor class.
				System.out.println("\n\n************************** The Shift Supervisor **************************\n");
			}

			// checking if the current chosen employee is Instance of TeamLeader if yes we
			// will make the casting for it to use in different situations

			if (EmployeesInformation.get(Beginning) instanceof TeamLeader) {

				// Printing TeamLeader sentence for TeamLeader class.

				System.out
						.println("\n\n****************************** The Team Leader ******************************\n");
			}

			System.out.println(EmployeesInformation.get(Beginning)); // Print the informations about all Employees
			System.out.println("\n===========================================================================\n");
		}

		// Extra Printing the total salary for all employees
		System.out.println(
				"\n#########The Total Salary for all Employees in the Factory is :" + TotalSalaryAllEmployees + " $\n");
		System.out.println("\n===========================================================================");

		ListGreaterThanAverage(EmployeesInformation);
	}

	// List Greater Than method that first calculate the average for the total
	// salary for all employees then it will print the informations for all the
	// employees who is greater than the average with all informations

	public static void ListGreaterThanAverage(ArrayList<Employee> EmployeesInformation) {

		double TotalSalaryAllEmployees = 0.0;

		// We need a for loop to calculate the total salary for all Employees that they
		// written in the Array List also we will use the total salary in the average.

		for (int Beginning = 0; Beginning < EmployeesInformation.size(); Beginning++) {

			// checking if the current chosen employee is Instance of Production Worker if
			// yes we will make the casting for it to use in different situations

			if (EmployeesInformation.get(Beginning) instanceof ProductionWorker)

				TotalSalaryAllEmployees += ((ProductionWorker) EmployeesInformation.get(Beginning)).getTotalSalary();

			// checking if the current chosen employee is Instance of ShiftSupervisor if yes
			// we will make the casting for it to use in different situations

			else if (EmployeesInformation.get(Beginning) instanceof ShiftSupervisor)

				TotalSalaryAllEmployees += ((ShiftSupervisor) EmployeesInformation.get(Beginning)).getTotalSalary();

			// checking if the current chosen employee is Instance of TeamLeader if yes we
			// will make the casting for it to use in different situations

			else if (EmployeesInformation.get(Beginning) instanceof TeamLeader)

				TotalSalaryAllEmployees += ((TeamLeader) EmployeesInformation.get(Beginning)).getTotalSalary();
		}

		double Average = TotalSalaryAllEmployees / EmployeesInformation.size();

		System.out.println("\nThe Average price for the Employees is : " + Average + " $");

		System.out.println(
				"\n\nThe List of The Employees whose Total Salary is greater than average is and printing all their Informations:\n");

		for (int begin = 0; begin < EmployeesInformation.size(); begin++) {

			// checking if the current chosen employee is Instance of Production Worker if
			// yes we will make the casting for it to use in different situations
			if (EmployeesInformation.get(begin) instanceof ProductionWorker) {

				ProductionWorker ProductionWorker1 = (ProductionWorker) EmployeesInformation.get(begin);

				if (ProductionWorker1.getTotalSalary() > Average) // if case to print the information for production
																	// worker if this worker salary is greater than
																	// average
					System.out.println(ProductionWorker1);

			}

			// checking if the current chosen employee is Instance of ShiftSupervisor if yes
			// we will make the casting for it to use in different situations

			else if (EmployeesInformation.get(begin) instanceof ShiftSupervisor) {

				ShiftSupervisor ShiftSupervisor1 = (ShiftSupervisor) EmployeesInformation.get(begin);

				if (ShiftSupervisor1.getTotalSalary() > Average) // if case to print the information for Shift
																	// Supervisor if this worker salary is greater than
																	// average

					System.out.println(ShiftSupervisor1);
				System.out.println("\n************************************************");

			}

			// checking if the current chosen employee is Instance of TeamLeader if yes we
			// will make the casting for it to use in different situations

			else if (EmployeesInformation.get(begin) instanceof TeamLeader) {

				TeamLeader TeamLead = (TeamLeader) EmployeesInformation.get(begin);

				if (TeamLead.getTotalSalary() > Average) // if case to print the information for Team Leader if this
															// worker salary is greater than average

					System.out.println(TeamLead);

			}

		}

	}

}
