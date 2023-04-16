// 1191602    MAHMOUD SAMARA       COMP231       SEC2          FINAL PROJECT

public class Truck extends Vehicles {
	private boolean AirConditionON; // boolean AirConditionON we will use it to know the condition of AirConditionON
									// for the chosen truck.
	private int Power; // Power we will use it to know the specific Power for the chosen truck.

	private int NumberOfSeats; // NumberOfSeats we will use it to know the specific NumberOfSeats for the
								// chosen truck.

	private int NumberOfWheels; // NumberOfWheels we will use it to know the specific NumberOfWheels for the
	// chosen truck.

	public int getNumberOfSeats() { // declare a method it's called NumberOfSeats and it's kind is integer and it
									// returns NumberOfSeats for the truck.
		return NumberOfSeats;
	}

	public void setNumberOfSeats(int numberOfSeats) { // declare a method it's called NumberOfSeats and it sets a new
														// NumberOfSeats for the new given or the new chosen truck.

		this.NumberOfSeats = numberOfSeats;
	}

	public int getNumberOfWheels() { // declare a method it's called NumberOfWheels and it's kind is integer and it
		// returns NumberOfWheels for the truck.
		return NumberOfWheels;
	}

	public void setNumberOfWheels(int NumberOfWheels) { // declare a method it's called NumberOfWheels and it sets a new
		// NumberOfWheels for the new given or the new chosen truck.

		this.NumberOfWheels = NumberOfWheels;
	}

	public int getPower() { // declare a method it's called Power and it's kind is integer and it returns
							// Power for the truck.
		return Power;
	}

	public void setPower(int power) { // declare a method it's called Power and it sets a new Power for the new given
										// or the new chosen truck.

		this.Power = power;
	}

	public boolean isAirConditionON() { // declare a method it's called AirConditionON and it's kind is boolean and it
										// returns AirCondition for the truck
		return AirConditionON;
	}

	public void setAirConditionON(boolean airConditionON) { // declare a method it's called AirConditionON and it sets a
															// new AirCondition for the new given or the new chosen
															// truck.

		this.AirConditionON = airConditionON;
	}

	@Override
	public void setAirConditionOn() { // Definning a method to set the air condition to on so it is condition is true
		this.setAirConditionON(true);

	}

	@Override
	public void setAirConditionOff() { // Definning a method to set the air condition to off so it is condition is
										// false
		this.setAirConditionON(false);
	}

	// override method to check the type of engine that is entered in the input file
	// for the chosen vehicle if it is right the type of engine will be printed but
	// if it is false it will give an exception handling
	@Override
	public void setEngineType(String engineType) throws IllegalArgumentException {

		if (engineType.equalsIgnoreCase("Diesel") || engineType.equalsIgnoreCase("Hybrid")) {
			super.setEngineType(engineType);
		} else
			throw new IllegalArgumentException(
					"Error..... The type of Engine that is entered is wrong please check the input file again and correct it....");
	}

	// CostFor100km method to calculate the cost depend on situations first The
	// MiniVan uses diesel and hybrid only also when the air condition is off
	// is different in calculation when it is on so when it is on the Fuel
	// consumption of the Car increased by 20% when air-condition of the Car is ON
	@Override
	public double CostFor100km() {

		double PetrolPrice = (EngineType.equalsIgnoreCase("Hybrid")) ? PetroleumType.getGasolinePrice()
				: PetroleumType.getDieselPrice();
		double ExtraPetrolPrice = PetrolPrice * 1.2;

		// if statememt will happen if condition on and the engine is Diesel or hybrid
		
		if (AirConditionON) {
			CostFor100km = ((100 / FuelConsumption) * ExtraPetrolPrice);
		}
		// else will happen if condition off and the engine is Diesel or hybrid
		else {
			CostFor100km = (100 / FuelConsumption) * PetrolPrice;
		}

		return CostFor100km;
	}

	// An extra method to print a meesage to tell user how many the maximum weight
	// can the truck carry depend on number of axles( number of axles can be 2 or 3)
	// and depend on the result the message will appear

	public String MaxWeightOfGoodsToCarry() {
		int numofaxles = NumberOfWheels / 2;
		if (numofaxles == 2) {
			return " So the number of axles equal 2 then , The Maximum Weight Of Goods that this truck canCarry is : 20.000 bound";
		}
		return "So the number of axles equal 3 then , The Maximum Weight Of Goods that this truck canCarry is : 34.000 bound";
	}

	@Override
	// override method toString to return the MiniVan informations also it will
	// print
	// error message if there is any problem in the power or number of seats because
	// they must be positive numbers
	public String toString() {
		if (Power > 0 && NumberOfSeats > 0)
			return super.toString() + ",The NumberOfSeats for the Chosen Truck is :" + NumberOfSeats
					+ " , The number of Wheels is : " + NumberOfWheels + " ,," + MaxWeightOfGoodsToCarry()
					+ ",The Movable Distance for the Truck is : " + super.MovableDistance() + " KM , The Power  is : "
					+ Power + " ,AirConditionON = " + AirConditionON + " ,Cost for 100 km is : " + CostFor100km()
					+ "NIS\nSome informations about the Vehicle :" + super.InformationAboutVehicleBrand();
		if (Power < 0 && NumberOfSeats > 0)
			return super.toString() + ",The NumberOfSeats for the Chosen car is :" + NumberOfSeats
					+ ", The number of Wheels is : " + NumberOfWheels + " ,," + MaxWeightOfGoodsToCarry()
					+ ",The Movable Distance for the Truck is : " + super.MovableDistance()
					+ " KM , The Power is : Error..........Because the entered value for Power is 0 or negative and this can't happen  "
					+ ",AirConditionON = " + AirConditionON + " ,Cost for 100 km is : " + CostFor100km()
					+ "NIS\nSome informations about the Vehicle :" + super.InformationAboutVehicleBrand();

		if (Power > 0 && NumberOfSeats < 0)
			return super.toString()
					+ ",The NumberOfSeats for the Chosen car is :Error..........Because the entered number is 0 or negative and this can't happen"
					+ ", The number of Wheels is : " + NumberOfWheels + " ,," + MaxWeightOfGoodsToCarry()
					+ "  ,The Movable Distance for the Truck is : " + super.MovableDistance() + ", The Power is : "
					+ Power + " ,AirConditionON = " + AirConditionON + " ,Cost for 100 km is : " + CostFor100km()
					+ "NIS\nSome informations about the Vehicle :" + super.InformationAboutVehicleBrand();

		return super.toString()
				+ ",The NumberOfSeats for the Chosen car is : Error..........Because the entered number is 0 or negative and this can't happen"
				+ ", The number of Wheels is : " + NumberOfWheels + " ,," + MaxWeightOfGoodsToCarry()
				+ " ,The Movable Distance for the Truck is : " + super.MovableDistance()
				+ ",Power is :  Error..........Because the entered value for Power is 0 or negative and this can't happen "
				+ ",AirConditionON = " + AirConditionON + " ,Cost for 100 km is : " + CostFor100km()
				+ "NIS\nSome informations about the Vehicle :" + super.InformationAboutVehicleBrand();

	}

	// override method to compare between vehicles depend on the brand name
	@Override
	public int compareTo(Vehicles obj) {
		return this.getBrand().compareTo(obj.getBrand());
	}
}
