
// 1191602    MAHMOUD SAMARA       COMP231       SEC2          FINAL PROJECT

import java.util.Calendar;
import java.util.GregorianCalendar;

public class Owner {
	String Name; // Name we will use it to know the specific name for the Owner of the chosen car
					// or truck or Minivan.
	String RegistrationNo; // RegistrationNo we will use it to know the specific RegistrationNo for the
							// Owner of the chosen car
	// or truck or Minivan.
	String address; // address we will use it to know the specific address for the Owner of the
					// chosen car or truck or Minivan.
	String Tel; // Tel we will use it to know the specific Tel for the Owner of the
				// chosen car or truck or Minivan.
	GregorianCalendar DateOfRegistration; // DateOfRegistration we will use it to know the specific DateOfRegistration
											// for the Owner of the chosen car or truck or Minivan.

	public String getName() { // declare a method it's called Name and it's kind is String and it returns
								// Owner Name.
		return Name;
	}

	public void setName(String name) { // declare a method it's called Name and it sets a new Name for the new given or
										// the new chosen Owner.
		this.Name = name;
	}

	public String getPIN() {// declare a method it's called PIN and it's kind is String and it returns Owner
							// PIN.
		return RegistrationNo;
	}

	public void setPIN(String pIN) {// declare a method it's called PIN and it sets a new PIN for the new given or
									// the new chosen Owner.
		this.RegistrationNo = pIN;
	}

	public String getAddress() {// declare a method it's called Address and it's kind is String and it returns
								// Owner Address.
		return address;
	}

	public void setAddress(String address) { // declare a method it's called Address and it sets a new Address for the
												// new given or the new chosen Owner.
		this.address = address;
	}

	public String getMobileNo() {// declare a method it's called MobileNo and it's kind is String and it returns
									// Owner MobileNo.
		return Tel;
	}

	public void setMobileNo(String mobileNo) { // declare a method it's called MobileNo and it sets a new MobileNo for
												// the new given or the new chosen Owner.
		this.Tel = mobileNo;
	}

	public GregorianCalendar getDateOfRegistration() { // declare a method it's called DateOfRegistration and it's kind
														// is Date and it returns Owner DateOfRegistration.
		return DateOfRegistration;
	}

	public void setDateOfRegistration(GregorianCalendar dateOfRegistration) { // declare a method it's called
																				// DateOfRegistration and it sets a new
																				// DateOfRegistration for the new given
																				// or the new chosen Owner.
		this.DateOfRegistration = dateOfRegistration;
	}

	@Override
	// override method toString to return the Owner informations
	public String toString() {
		GregorianCalendar calender = new GregorianCalendar();
		String DateOfRegis = calender.get(Calendar.YEAR) + "/" + calender.get(Calendar.MONTH) + 1 + "/"
				+ calender.get(Calendar.DAY_OF_MONTH);
		return "Owner [Name=" + Name + ", Registration Number is =" + RegistrationNo + ", address=" + address
				+ ", The telephone number is =" + Tel + ", DateOfRegistration=" + DateOfRegis + "]";
	}

}
