// ASSIGNMENT 3        1191602        MAHMOUD SAMARA     COMP231      DR.HAFEZ BARGHOUTHI          SEC2

import java.util.Date;

// Defining the first class ( class Employee)
public class Employee {
	private String EmpName; // EmpName we will use it to know and print the name for the chosen Employee.
	private String EmpNumber; // EmpNumber we will use it to know and print the number for the chosen
								// Employee.
	private Date EmpHire_Date; // EmpHire_Date we will use it to know and print the date when the employee
								// started working in the factory.
	private Address EmpAddress; // EmpAddress we will use it to know and print the Address for the chosen
								// Employee and it is with all informations in class Address.

	// No-argument constructor it includes the default values about for the
	// variables.
	public Employee() {
		// default values for the different variables
		EmpName = " ";
		EmpNumber = " ";
		EmpHire_Date = new Date();
		EmpAddress = new Address();

	}

	// Constructing an Employee object that has the same name as the class itself
	// and it has several methods in different types and it is constructor with
	// arguments it includes different attributes.
	public Employee(String empname, String empnumber, Date hire_date, Address address) {
		super();
		this.EmpName = empname;
		this.EmpNumber = empnumber;
		this.EmpHire_Date = hire_date;
		this.EmpAddress = address;
	}

	public String getEmpName() { // declare a method it's called EmpName and it's kind is String and it returns
									// EmpName.

		return EmpName;
	}

	public void setEmpName(String name) { // declare a method it's called EmpName and it sets a new name for the new
											// given or the new chosen Employee.
		this.EmpName = name;
	}

	public String getEmpNumber() { // declare a method it's called EmpNumber and it's kind is String and it returns
									// EmpNumber.
		return EmpNumber;
	}

	public void setEmpNumber(String empnumber) { // declare a method it's called EmpNumber and it sets a new number for
													// the new given or the new chosen Employee.
		this.EmpNumber = empnumber;
	}

	public Date getHireDate() { // declare a method it's called HireDate and it's kind is Date and it returns
								// EmpHire_Date.
		return EmpHire_Date;
	}

	public void setHireDate(Date date) { // declare a method it's called HireDate and it sets a new date for the new
											// given or the new chosen Employee.
		this.EmpHire_Date = date;
	}

	public Address getAddress() { // declare a method it's called Address and it's kind is Address and it returns
									// EmpAddress.
		return EmpAddress;
	}

	public void setAddress(Address address) { // declare a method it's called address and it sets a new address for the
												// new given or the new chosen Employee.
		this.EmpAddress = address;
	}

	// Making a method to check the employee number to judge if it is true or fulse
	// depend on special casses that explained in the for loop inside the method.

	public boolean isEmpNumberValid() {
		// for loop to test the five characters of the number because they must be with
		// special way if not then it must return false . to be true must have every
		// thing as what we need..... 1. Checking if length for the employee number is 5
		// if
		// not then returns false it is 5 because must number must be like XXX_L.....2.
		// the first three characters must be integers from 0 to 9 if not return
		// false...... 3. 4th character must be '-' if not then it must return false
		// ...... 4.the fifth character is a charachter between A and M if no it will
		// return false.

		for (int Xdigit = 0; Xdigit < 5; Xdigit++)
			if (EmpNumber.length() == 5
					&& ((Xdigit < 3) && (EmpNumber.charAt(Xdigit) >= '0' && EmpNumber.charAt(Xdigit) <= '9'))
					&& EmpNumber.charAt(3) == '-' && (EmpNumber.charAt(4) >= 'A' && EmpNumber.charAt(4) <= 'M'))
				return true;

		return false;

	}

	@Override
	// toString method to print all the informations about the chosen Employee

	public String toString() {

		// We need if statement to check the employee number because it has special
		// casses and if it is false it must return an Error Messaga.

		if (isEmpNumberValid() == false)
			return "The Informations for The Employee is :\nThe Name is : " + EmpName + "\nThe Employee Number is : "
					+ "   Error......The entered number for the Employee is wrong and it is not like it is needed for the number , Please enter a right one."
					+ "\nThe Number Valid is :" + isEmpNumberValid() + "\nThe Hire Date is : " + EmpHire_Date
					+ "\n\n******The full Address is:*******\n" + EmpAddress + "\n";

		return "The Informations for The Employee is :\nThe Name is : " + EmpName + "\nThe Employee Number is : "
				+ EmpNumber + "\nThe Number Valid is :" + isEmpNumberValid() + "\nThe Hire Date is : " + EmpHire_Date
				+ "\n\n******The full Address is:*******\n" + EmpAddress + "\n";
	}

}