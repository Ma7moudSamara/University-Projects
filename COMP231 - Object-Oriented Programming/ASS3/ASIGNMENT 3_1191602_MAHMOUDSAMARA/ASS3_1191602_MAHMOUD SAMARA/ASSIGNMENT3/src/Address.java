// ASSIGNMENT 3       1191602        MAHMOUD SAMARA     COMP231      DR.HAFEZ BARGHOUTHI          SEC2

// Defining the class Address
public class Address {
	private String Street; // street we will use it to know the specific street for address for the chosen
							// Employee.
	private String State; // state we will use it to know the specific state for address for the chosen
							// Employee.
	private String City; // city we will use it to know the specific city for address for the chosen
							// Employee.
	private int Zipcode; // zipcode we will use it to know the zipcode for the city that is in the
							// address for the chosen Employee.

	// No-argument constructor it includes the default values about for the
	// variables.
	public Address() {
		// default values for the different variables
		Street = "";
		State = "";
		City = "";
		Zipcode = 0;
	}

	public Address(String street, String state, String city, int zipcode) {
		this.Street = street;
		this.State = state;
		this.City = city;
		this.Zipcode = zipcode;
	}

	public String getStreet() { // declare a method it's called Street and it's kind is String and it returns
								// the Street of the address of the Employee.
		return Street;
	}

	public void setStreet(String street) { // declare a method it's called Street and it sets a new Street for the new
											// address for given or the new chosen Employee.
		this.Street = street;
	}

	public String getState() { // declare a method it's called State and it's kind is String and it returns
								// State of the address of the Employee.
		return State;
	}

	public void setState(String state) { // declare a method it's called State and it sets a new State for the new
											// address for given or the new chosen Employee.
		this.State = state;
	}

	public String getCity() { // declare a method it's called City and it's kind is String and it returns City
								// of the address of the Employee.
		return City;
	}

	public void setCity(String city) { // declare a method it's called City and it sets a new City for the new address
										// for given or the new chosen Employee.
		this.City = city;
	}

	public int getZipcode() { // declare a method it's called Zipcode and it's kind is int and it returns
								// Zipcode of the address of the Employee.
		return Zipcode;
	}

	public void setZipcode(int zipcode) { // declare a method it's called Zipcode and it sets a new Zipcode for the new
											// address for given or the new chosen Employee.
		this.Zipcode = zipcode;
	}

	// Overrides toString() method to return all the informations about the Employee
	// address.
	@Override
	public String toString() {

		// We need if statement to check the zipcode because there is no any zipcode
		// negative

		if (Zipcode < 0)
			return "\nThe Street is :" + Street + "\nThe State is: " + State + "\nThe City is:" + City
					+ "\nThe Zipcode is: Please check the entered Zipcode again because the entered Zipcode is wrong.";

		return "\nThe Street is :" + Street + "\nThe State is: " + State + "\nThe City is:" + City
				+ "\nThe Zipcode is: " + Zipcode;
	}

}
