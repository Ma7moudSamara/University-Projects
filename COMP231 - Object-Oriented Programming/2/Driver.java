// ASSIGNMENT 2           1191602          MAHMOUD SAMARA     COMP231      DR.HAFEZ BARGHOUTHI       SEC2

// This assignment is a JAVA program that shows a simple explain of car agency companies with many attributes that the car has it.

// THE MAIN METHOD
public class Driver {

	public static void main(String[] args) {

		System.out.println(
				"                *************************** Welcome to the program *************************** \n ");
		System.out.println(
				" <<.........This program shows the explain of agency for several cars and show all information for each car from color , price , age , manufactureby, when it made and when the end of guarantee........ >> \n ");
		System.out
				.println("                ####################### Palestinian Car Agency  ####################### \n ");

		Car Default_Mercedes = new Car();

		Car[] cars = new Car[5];

		cars[0] = new Car("512-S", 2003, 6, "silver", 90000.00, "bmw", 2025, 11);

		cars[1] = new Car("103-M", 2022, 7, "white", 55000.00, "kia", 2022, 8);

		cars[2] = new Car("287-G", 2014, 4, "pink", 86000.00, "hyundai", 2013, 10);

		cars[3] = new Car("144-A", 2019, 14, "black", 240000.00, "range_rover", 2024, 3);

		cars[4] = new Car("182-X", 1998, 13, "blue", 40000.00, "lambarghini", 2001, 6);

		System.out.println("\n---------------------------------------------------");
		System.out.println("\nFirst I will print the information for the default car (Mercedes) :");

		System.out.println(Default_Mercedes.printCarInfo().toUpperCase()); // print sentence to print the information
																			// for the default car (Mercedes) and of
																			// course all letters are capital.
		System.out.println("\n**********");
		System.out.println(Default_Mercedes.getCarAge().toUpperCase()); // print sentence to print the age that was
		// calculated in class Car for the default car
		// (Mercedes) and of course every thing capital.
		System.out.println("\n**********");
		System.out.println(Default_Mercedes.getCalculateGuarantee().toUpperCase()); // print sentence to print the
		// guarante that was calculated in
		// class Car for the default car
		// (Mercedes) and of course every
		// thing are capital.

		System.out.println("---------------------------------------------------");

		printCarsInfo(cars);
		Car details = MaxPrice(cars);

		System.out.println("\nTHE INFORMATION FOR THE CAR WITH THE MOST EXPENSIVE PRICE IS :");
		System.out.println("*****************************************");

		System.out.println(details.printCarInfo().toUpperCase()); // print sentence to print the information for the
																	// given five cars and of course all letters are
																	// capital.
		System.out.println("\n**********");
		System.out.println(details.getCarAge().toUpperCase()); // print sentence to print the age that was calculated in
																// class Car for the given five cars and of course every
																// thing capital.
		System.out.println("\n**********");
		System.out.println(details.getCalculateGuarantee().toUpperCase()); // print sentence to print the guarantee that
																			// was calculated in class Car for the given
																			// five cars and of course every thing are
																			// capital.

	}

	// Making a function it's called printCarsInfo that print all information about
	// the five cars with ages and guarantee due to that was calculated in class Car
	// also it print the other information that was written by me in the above
	// arrays.
	public static void printCarsInfo(Car[] cars) {
		for (int i = 0; i < cars.length; ++i) {
			System.out.println(cars[i].printCarInfo().toUpperCase());
			System.out.println("\n**********");
			System.out.println(cars[i].getCarAge().toUpperCase());
			System.out.println("\n**********");
			System.out.println(cars[i].getCalculateGuarantee().toUpperCase());
			System.out.println(
					"---------------------------------------------------------------------------------------------------");

		}
	}

	// Making a function it's called Car MaxPrice that find the car with the most
	// expensive price and print it with all its information.
	public static Car MaxPrice(Car[] cars) {
		double maxprice = cars[0].getPrice();
		int sign = 0;
		for (int carmax = 0; carmax < cars.length; carmax++) {
			if (maxprice < cars[carmax].getPrice()) {
				sign = carmax;
				maxprice = cars[carmax].getPrice();
			}
		}
		return cars[sign];
	}

}