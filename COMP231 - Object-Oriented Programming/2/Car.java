// ASSIGNMENT 2        1191602        MAHMOUD SAMARA     COMP231      DR.HAFEZ BARGHOUTHI          SEC2

// This assignment is a JAVA program that shows a simple explain of car agency companies with many attributes that the car has it.
import java.util.Date;

public class Car {
	// defining the instance viriables
	private String PlateNo; // PlateNo we will use it to know to numbers in the plate for the chosen car.
	private int yearmanufacture; // yearmanufacture will use it for the year that the car was made in it.
	private int monthmanufacture; // monthmanufacture will use it for the month that the car was made in it.
	private String color; // color we will use it to know the color for the chosen or given car.
	private double price; // price we will use it to know the price for the chosen or given car.
	private String manufactureby; // manufactureby we will use it to know the company that designed the given or
									// chosen car.
	private int guaranteedueyear; // guaranteedueyear will use it for the year that guarantee will end in it.
	private int guaranteeduemonth; // guaranteeduemonth will use it for the month that guarantee will end in it.

	// Constructing a Car object that has the same name as the class itself we will
	// put in it all information that given in the schedule in question.
	// No-argument constructor it includes the default information about the given
	// car (Mercedes Benz)
	@SuppressWarnings("deprecation")
	public Car() {
		Date Schedule = new Date();
		PlateNo = "0123-A";
		yearmanufacture = Schedule.getYear() + 1900;
		monthmanufacture = Schedule.getMonth() + 1;
		color = "red";
		price = 50000.00;
		manufactureby = "Mercedes";
		guaranteedueyear = Schedule.getYear() + 1900;
		guaranteeduemonth = Schedule.getMonth() + 7;
		if (guaranteeduemonth > 12) {
			guaranteedueyear = guaranteedueyear + 1;
			guaranteeduemonth = guaranteeduemonth - 12;
		}
	}

	// Constructing a Car object that has the same name as the class itself and it
	// has several methods in different types.
	// constructor with arguments it includes 8 attributes
	public Car(String PlateNo, int yearmanufacture, int monthmanufacture, String color, double price,
			String manufactureby, int guaranteedueyear, int guaranteeduemonth) {
		this.PlateNo = PlateNo;
		this.yearmanufacture = yearmanufacture;
		this.monthmanufacture = monthmanufacture;
		this.color = color;
		this.price = price;
		this.manufactureby = manufactureby;
		this.guaranteedueyear = guaranteedueyear;
		this.guaranteeduemonth = guaranteeduemonth;

	}

	public int getYearManufacture() { // declare a method it's called YearManufacture and it's kind is integer and it
										// returns YearManufacture.
		return yearmanufacture;
	}

	public String getColor() { // declare a method it's called color and it's kind is a String and it returns
		// the color of the car.
		return color;
	}

	public double getPrice() { // declare a method it's called price and it's kind is double and it returns the
		// price of the car.
		return price;
	}

	public int getMonthManufacture() { // declare a method it's called MonthManufacture and it's kind is integer and it
										// returns MonthManufacture.
		return monthmanufacture;
	}

	public void setYearManufacture(int yearmanufacture) {// declare a method it's called YearManufacture and it sets a
															// new yearmanufacture for the new given or the new chosen
															// car.
		this.yearmanufacture = yearmanufacture;
	}

	public void setMonthManufacture(int monthmanufacture) { // declare a method it's called MonthManufacture and it sets
															// a new monthmanufacture for the new given or the new
															// chosen car.
		this.monthmanufacture = monthmanufacture;
	}

	public void setColor(String color) { // declare a method it's called color and it sets a new color for the new given
											// or the new chosen car.
		this.color = color;
	}

	public void setGuarantee(int month, int year) {
		this.guaranteedueyear = year;
		this.guaranteeduemonth = month;
	}

	@SuppressWarnings("deprecation")
	// declare a method it's called CarAge and it returns the age of the given or
	// the chosen car in years and months and it print the information as a String.
	public String getCarAge() {
		Date Schedule = new Date();
		int currentYear = Schedule.getYear() + 1900;
		int currentMonth = Schedule.getMonth() + 1;
		if (monthmanufacture > 12) {
			yearmanufacture = yearmanufacture + 1;
			monthmanufacture = monthmanufacture - 12;
		}
		int calculate_year = (currentYear - yearmanufacture);
		int calculate_month = 0;

		// we need this if statement because when monthmanufacture is bigger than
		// current month the program calculate will be wrong for example the car
		// made in 2005 in 8 month , and now we are in 2015 month 5 in normal
		// way program print age is 10 years and 3 months and this is wrong ,
		// the true is 9 years and 9 months.

		if (currentMonth > monthmanufacture) {
			calculate_month = currentMonth - monthmanufacture;
		} else {
			calculate_year = (((currentYear * 12) + currentMonth) - ((yearmanufacture * 12) - monthmanufacture));
			calculate_year = calculate_year / 12;
			calculate_month = (currentYear * 12 + currentMonth - yearmanufacture * 12 - monthmanufacture);
			calculate_month = calculate_month % 12;
		} // we need this if statement because when currentYear is less than
			// yearmanufacture the car is not made yet and the calculate will be wrong same
			// thing when the two years are equal but currentmont is less than
			// monthmanufacture.
		if (yearmanufacture > currentYear) {
			return ("Error......Something went wrong because the date is entered show that this car isn't yet manufactured");
		}
		if (yearmanufacture == currentYear && monthmanufacture > currentMonth) {
			return ("Error......Something went wrong because the date is entered show that this car isn't yet manufactured");
		}
		return ("the age of the car is : " + calculate_year + " year(s) and " + calculate_month + " month(s).");

	}

	public String getManufactureBy() { // declare a method it's called ManufactureBy and it's kind is a String and it
										// returns the ManufactureBy (the company created the car ).
		return manufactureby;
	}

	public String printCarInfo() { // declare a method it's called CarInfo by it we can print all the information
									// about the car from price , color, guarantee...............
		return ("\nThe car informations is : \n\n## the PlateNo is : " + PlateNo
				+ ".\n\nthe yearManufacture of the car is : " + yearmanufacture
				+ " year(s).\tthe monthManufacture of the car is : " + monthmanufacture
				+ " month(s) .\n\nthe color of the car is : " + color + ". \n\nthe price of the car is = " + price
				+ "\n\nthe car is manufactureBy (Designed by) : " + manufactureby
				+ ". \n\nthe guaranteeDueYear for the car is : " + guaranteedueyear
				+ ". \tthe guaranteeDueMonth for the car is : " + guaranteeduemonth + " ##");

	}

	@SuppressWarnings("deprecation")

	public String getCalculateGuarantee() { // declare a method it's called CalculateGuarantee and it calculate the
											// guarantee for the given or the chosen car.
		Date Schedule = new Date();
		int currentYear = Schedule.getYear() + 1900;
		int currentMonth = Schedule.getMonth() + 1;
		if (guaranteeduemonth > 12) {
			guaranteedueyear = guaranteedueyear + 1;
			guaranteeduemonth = guaranteeduemonth - 12;
		}
		int year = guaranteedueyear - currentYear;
		int month = 0;
		// we need this if statement because when currentMonth is bigger than
		// guaranteeduemonth the program calculate will be wrong for example the current
		// time is 2018 and 8 month , and guarantee in 2024 month 2 in normal
		// way program print age is 6 years and 6 months and this is wrong ,
		// the true is 5 years and 6 months.
		if (currentMonth <= guaranteeduemonth) {
			month = guaranteeduemonth - currentMonth;
		} else {
			year = year - 1;

			month = guaranteeduemonth + 12 - currentMonth;
		}
		// we need this if statement because when guaranteeyear is less than current
		// year the car will be expired and the calculate will be wrong same thing when
		// the two years are equal but guaranteemonth is less than currentmont.
		if (guaranteedueyear < currentYear || guaranteedueyear == currentYear && guaranteeduemonth < currentMonth) {

			return ("Error......Something went wrong because the date is entered show that this car guarantee is expired");
		}

		return ("the guarantee for the car is : " + year + " year(s) " + month + " month(s) ");

	}

}