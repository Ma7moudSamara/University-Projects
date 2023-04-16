// ASSIGNMENT 3        1191602        MAHMOUD SAMARA     COMP231      DR.HAFEZ BARGHOUTHI          SEC2

import java.util.Date;

// Definning the sub class that is ProductionWorker that extends from  the super class Employee
public class ProductionWorker extends Employee {

	private int Shift; // shift we will use it to know and print the shift that the employee worked in
						// day or night.
	private double PayRate; // payRate we will use it to know and print the payRate for the Employee.
	private double NumHoursInMonth; // NumHoursInMonth we will use it to know and print the number of hours that
									// employee worked in a month.

	// No-argument constructor it includes the default values about for the
	// variables.
	public ProductionWorker() {
		// default values for the different variables
		Shift = 0;
		PayRate = 0.0;
		NumHoursInMonth = 0.0;
	}

	// Constructing an ProductionWorker object that has the same name as the class
	// itself
	// and it has several methods in different types and it is constructor with
	// arguments it includes different attributes also it extends some informations
	// from Employee class.
	public ProductionWorker(String EmpName, String EmpNumber, Date EmpHire_Date, Address EmpAddress, int Shift,
			double PayRate, double NumHoursInMonth) {
		super(EmpName, EmpNumber, EmpHire_Date, EmpAddress);

		this.Shift = Shift;
		this.PayRate = PayRate;
		this.NumHoursInMonth = NumHoursInMonth;
	}

	public int getShift() { // declare a method it's called Shift and it's kind is int and it returns Shift.
		return Shift;
	}

	public void setShift(int shift) { // declare a method it's called Shift and it sets a new shift ( day or night )
										// for the new given
										// or the new chosen Employee.
		this.Shift = shift;

	}

	public double getPayRate() { // declare a method it's called PayRate and it's kind is double and it returns
									// PayRate.
		return PayRate;
	}

	public void setPayRate(double payRate) { // declare a method it's called PayRate and it sets a new PayRate for the
												// new given or the new chosen Employee.
		this.PayRate = payRate;
	}

	public double getNumHoursInMonth() { // declare a method it's called HoursInMonth and it's kind is double and it
											// returns HoursInMonth.
		return NumHoursInMonth;
	}

	public void setNumHoursInMonth(double HoursInMonth) { // declare a method it's called HoursInMonth and it sets a new
															// number of hours worked in month for the new given or the
															// new chosen Employee.
		this.NumHoursInMonth = HoursInMonth;
	}

	// get total salary method it calculate depend on the shift :Day shift worker
	// should at least works 8 hours with rate per hour, and for any extra hours get
	// 1.25 hours instead of it, but night shift have to work at least 7 hours and
	// for any extra hours get 1.5 hours instead of it.also Day shifts has only one
	// value, 1 or 2 and others not allowed. Calculation of salary should be per
	// month and month is 26 days/work.

	public double getTotalSalary() {

		double ExtraCalculate = NumHoursInMonth / 26.0;

		if (Shift == 1) {
			if (ExtraCalculate > 0 && ExtraCalculate <= 8 && PayRate > 0) // because for shift night the employee if
																			// work less than or equal 8 hours per day
																			// has different calculate.
				return PayRate * NumHoursInMonth;

			if (ExtraCalculate > 8 && PayRate > 0) // this if statement to calculate the bonus if the employee work more
													// than 8
				// hours in day shift then the hour will be 1.25 .
				return (PayRate * 208) + (NumHoursInMonth - 208) * PayRate * 1.25;
		}

		if (Shift == 2) {
			if (ExtraCalculate > 0 && ExtraCalculate <= 7 && PayRate > 0) // because for shift night the employee if
																			// work less than or equal 7 hours per day
																			// has different calculate.
				return PayRate * NumHoursInMonth;

			if (ExtraCalculate > 7 && PayRate > 0) // this if statement to calculate the bonus if the employee work more
													// than 7 hours in night shift then the hour will be 1.50 .
				return (PayRate * 182) + (NumHoursInMonth - 182) * PayRate * 1.50;
		}
		return 0;

	}

	// Overrides toString() method to it's SuperClass
	@Override
	public String toString() {

		// we need if statement for the shift and number of hours in month and pay rate
		// because they
		// have special condition so any wrong enter from the user then the program must
		// print error message depend on the error and sometimes the salary will change
		// depend on that and in situations it will equal 0.0

		if (Shift == 1 && (NumHoursInMonth > 0) && (PayRate > 0))
			return super.toString() + "\nThe Shift is : (" + Shift
					+ ")\nThe Shift kind is : Day\nThe Hourly Pay Rate is : " + PayRate
					+ "\nThe Number of Hours Per Month is : " + NumHoursInMonth
					+ "\nThe Total Salary to get after calculation is :" + getTotalSalary() + " $";

		if (Shift == 2 && (NumHoursInMonth > 0) && (PayRate > 0))
			return super.toString() + "\nThe Shift is : (" + Shift
					+ ")\nThe Shift kind is : Night\nThe Hourly Pay Rate is : " + PayRate
					+ "\nThe Number of Hours Per Month is : " + NumHoursInMonth + ""
					+ "\nThe Total Salary to get after calculation is :" + getTotalSalary() + " $";

		if (Shift == 1 && (NumHoursInMonth > 0) && (PayRate < 0))
			return super.toString() + "\nThe Shift is : (" + Shift
					+ ")\nThe Shift kind is : Day\nThe Hourly Pay Rate is : Error ........ The Enterd Pay Rate is wrong because the enterd number is negative."
					+ "\nThe Number of Hours Per Month is : " + NumHoursInMonth
					+ "\nThe Total Salary to get after calculation is :" + getTotalSalary()
					+ " $             <<<<Error ....... Because there is a wrong input is entered from Production Worker Inputs , please check the inputs again to calculate the Total Salary>>>>";

		if (Shift == 2 && (NumHoursInMonth > 0) && (PayRate < 0))
			return super.toString() + "\nThe Shift is : (" + Shift
					+ ")\nThe Shift kind is : Night\nThe Hourly Pay Rate is :Error ........ The Enterd Pay Rate is wrong because the enterd number is negative."
					+ "\nThe Number of Hours Per Month is : " + NumHoursInMonth + ""
					+ "\nThe Total Salary to get after calculation is :" + getTotalSalary()
					+ " $         <<<<Error ....... Because there is a wrong input is entered from Production Worker Inputs , please check the inputs again to calculate the Total Salary>>>>";
		if (Shift == 1 && (NumHoursInMonth < 0) && (PayRate > 0))
			return super.toString() + "\nThe Shift is : (" + Shift
					+ ")\nThe Shift kind is : Day\nThe Hourly Pay Rate is : " + PayRate
					+ "\nThe Number of Hours Per Month is :Error ....... The number enterd is wrong Please Enter a right number of hours per month because the entered number is less than (0) ----> ( Negative )."
					+ "\nThe Total Salary to get after calculation is :" + getTotalSalary()
					+ " $             <<<<Error ....... Because there is a wrong input is entered from Production Worker Inputs , please check the inputs again to calculate the Total Salary>>>>";
		if (Shift == 2 && (NumHoursInMonth < 0) && (PayRate > 0))
			return super.toString() + "\nThe Shift is : (" + Shift
					+ ")\nThe Shift kind is : Night\nThe Hourly Pay Rate is : " + PayRate
					+ "\nThe Number of Hours Per Month is :Error ....... The number enterd is wrong Please Enter a right number of hours per month because the entered number is less than (0) ----> ( Negative )."
					+ "\nThe Total Salary to get after calculation is :" + getTotalSalary()
					+ " $           <<<<Error ....... Because there is a wrong input is entered from Production Worker Inputs , please check the inputs again to calculate the Total Salary>>>>";

		if (Shift == 1 && (NumHoursInMonth < 0) && (PayRate < 0))
			return super.toString() + "\nThe Shift is : (" + Shift
					+ ")\nThe Shift kind is : Day\nThe Hourly Pay Rate is : Error ........ The Enterd Pay Rate is wrong because the enterd number is negative.\n"
					+ "\nThe Number of Hours Per Month is :Error ....... The number enterd is wrong Please Enter a right number of hours per month because the entered number is less than (0) ----> ( Negative ).\n"
					+ "\nThe Total Salary to get after calculation is :" + getTotalSalary()
					+ " $          <<<<Error ....... Because there is a wrong input is entered from Production Worker Inputs , please check the inputs again to calculate the Total Salary>>>>";

		if (Shift == 2 && (NumHoursInMonth < 0) && (PayRate < 0))
			return super.toString() + "\nThe Shift is : (" + Shift
					+ ")\nThe Shift kind is : Night\nThe Hourly Pay Rate is : Error ........ The Enterd Pay Rate is wrong because the enterd number is negative.\n"
					+ "\nThe Number of Hours Per Month is :Error ....... The number enterd is wrong Please Enter a right number of hours per month because the entered number is less than (0) ----> ( Negative ).\n"
					+ "\nThe Total Salary to get after calculation is :" + getTotalSalary()
					+ " $         <<<<Error ....... Because there is a wrong input is entered from Production Worker Inputs , please check the inputs again to calculate the Total Salary>>>>";

		if ((Shift != 1 || Shift != 2) && (NumHoursInMonth > 0) && (PayRate > 0))
			return super.toString() + "\nThe Shift is : Error the number (" + Shift
					+ ") that is for the Shift of The Production worker is entered is wrong , Please check it.\nThe Hourly Pay Rate is : "
					+ PayRate + "\nThe Number of Hours Per Month is :" + NumHoursInMonth
					+ "\nThe Total Salary to get after calculation is :" + getTotalSalary()
					+ " $     <<<<Error ....... Because there is a wrong input is entered from Production Worker Inputs , please check the inputs again to calculate the Total Salary>>>>";

		if ((Shift != 1 || Shift != 2) && (NumHoursInMonth > 0) && (PayRate < 0))
			return super.toString() + "\nThe Shift is : Error the number (" + Shift
					+ ") that is for the Shift of The Production worker is entered is wrong , Please check it.\nThe Hourly Pay Rate is : Error ........ The Enterd Pay Rate is wrong because the enterd number is negative."
					+ "\nThe Number of Hours Per Month is :" + NumHoursInMonth
					+ "\nThe Total Salary to get after calculation is :" + getTotalSalary()
					+ " $       <<<<Error ....... Because there is a wrong input is entered from Production Worker Inputs , please check the inputs again to calculate the Total Salary>>>>";

		if ((Shift != 1 || Shift != 2) && (NumHoursInMonth < 0) && (PayRate > 0))
			return super.toString() + "\nThe Shift is : Error the number (" + Shift
					+ ") that is for the Shift of The Production worker is entered is wrong , Please check it.\nThe Hourly Pay Rate is : "
					+ PayRate
					+ "\nThe Number of Hours Per Month is :Error ....... The number enterd is wrong Please Enter a right number of hours per month because the entered number is less than (0) ----> ( Negative )."
					+ "\nThe Total Salary to get after calculation is :" + getTotalSalary()
					+ " $          <<<<Error ....... Because there is a wrong input is entered from Production Worker Inputs , please check the inputs again to calculate the Total Salary>>>>";

		return super.toString()
				+ "\nThe Shift is : Error the number of shift that is entered is wrong because the number (" + Shift
				+ ") is not (1) OR (2)  and  the number of shift must be 1 or 2 so please enter the right number of shift.\n"
				+ "\nThe Hourly Pay Rate is : Error ........ The Enterd Pay Rate is wrong because the enterd number is negative.\n"
				+ "\nThe Number of Hours Per Month: Error..... Wrong number enterd for number of hours per month the entered number is negative.\n"
				+ "\nThe Total Salary to get after calculation is :" + getTotalSalary()
				+ " $        <<<<Error ....... Because there is a wrong input is entered from Production Worker Inputs , please check the inputs again to calculate the Total Salary>>>>";
	}
}
