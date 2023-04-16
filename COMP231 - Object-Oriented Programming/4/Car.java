// 1191602    MAHMOUD SAMARA       COMP231       SEC2          FINAL PROJECT

public class Car extends Vehicles {
	private int NumberOfSeats; // NumberOfSeats we will use it to know the specific NumberOfSeats for the
								// chosen car.
	private int Power; // Power we will use it to know the specific Power for the chosen car.
	private boolean AirConditionON; // boolean AirConditionON we will use it to know the condition of AirConditionON
									// for the chosen car.

	public int getNumberOfSeats() { // declare a method it's called NumberOfSeats and it's kind is integer and it
									// returns NumberOfSeats for the car.
		return NumberOfSeats;
	}

	public void setNumberOfSeats(int numberOfSeats) { // declare a method it's called NumberOfSeats and it sets a new
														// NumberOfSeats for the new given or the new chosen car.

		this.NumberOfSeats = numberOfSeats;

	}

	public int getPower() { // declare a method it's called Power and it's kind is integer and it
							// returns Power for the truck.
		return Power;
	}

	public void setPower(int power) { // declare a method it's called Power and it sets a new Power for the new given
										// or the new chosen truck.

		this.Power = power;
	}

	public boolean isAirConditionON() { // declare a method it's called AirConditionON and it's kind is boolean and it
										// returns AirCondition for the car
		return AirConditionON;
	}

	public void setAirConditionON(boolean airConditionON) { // declare a method it's called AirConditionON and it sets a
															// new AirCondition for the new given or the new chosen car.
		this.AirConditionON = airConditionON;
	}

	@Override
	public void setAirConditionOn() { // Definning a method to set the air condition to on so it is condition is true
		setAirConditionON(true);

	}

	@Override
	public void setAirConditionOff() { // Definning a method to set the air condition to off so it is condition is
										// false
		setAirConditionON(false);
	}

	// override method to check the type of engine that is entered in the input file
	// for the chosen vehicle if it is right the type of engine will be printed but
	// if it is false it will give an exception handling
	@Override
	public void setEngineType(String engineType) throws IllegalArgumentException {

		if (engineType.equalsIgnoreCase("Gasoline") || engineType.equalsIgnoreCase("Hybrid")) {
			super.setEngineType(engineType);
		} else
			throw new IllegalArgumentException(
					"Error..... The type of Engine that is entered is wrong please check the input file again and correct it....");
	}

	// CostFor100km method to calculate the cost depend on situations first The Car
	// uses only gasoline engine and hybrid also when the air condition is off
	// is different in calculation when it is on so when it is on the Fuel
	// consumption of the Car increased by 10% when air-condition of the Car is ON
	// so the cost is mutiply by 1.1 times

	@Override
	public double CostFor100km() {
		double cost100km = 0.0;
		double ExtraFuelGas = PetroleumType.getGasolinePrice() * 1.1;

		// if statememt will happen if condition on and the engine is gasoline or the
		// engine is Hybrid but both take gasoline price
		if (AirConditionON) {
			cost100km = ((100 / FuelConsumption) * ExtraFuelGas);
		}

		// if statememt will happen if condition off and the engine is Gasoline or the
		// engine is Hybrid but both take gasoline price
		else {

			cost100km = (100 / FuelConsumption) * PetroleumType.getGasolinePrice();

		}

		return cost100km;
	}

	// An Extra method that can calculate the maximum speed for the car depend on
	// the horse power
	public double HigestSpeedOfCar() {
		double MaxSpeed = 0.0;
		if (Power > 0)
			MaxSpeed = Math.cbrt(Power) * 20.0;
		return MaxSpeed;
	}

	// override method toString to return the car informations also it will print
	// error message if there is any problem in the power or number of seats because
	// they must be positive numbers

	@Override
	public String toString() {
		if (Power > 0 && NumberOfSeats > 0)
			return super.toString() + ",The NumberOfSeats for the Chosen car is :" + NumberOfSeats
					+ " ,The Movable Distance for the car is : " + super.MovableDistance() + " KM  , The Power : "
					+ Power + " ,AirConditionON = " + AirConditionON + " ,THE Cost for 100 KM is : " + CostFor100km()
					+ " NIS  ,The Highest speed that the car can get to it is = " + HigestSpeedOfCar()
					+ " KM\nSome informations about the Vehicle :" + super.InformationAboutVehicleBrand();

		if (Power > 0 && NumberOfSeats < 0)
			return super.toString()
					+ ",The NumberOfSeats for the Chosen car is : Error..........Because the entered number is 0 or negative and this can't happen  "
					+ ",The Movable Distance for the car is : " + super.MovableDistance() + " KM  , The Power is : "
					+ Power + " ,AirConditionON = " + AirConditionON + " ,THE Cost for 100 KM is : " + CostFor100km()
					+ " NIS ,The Highest speed that the car can get to it is = " + HigestSpeedOfCar()
					+ " KM\nSome informations about the Vehicle :" + super.InformationAboutVehicleBrand();

		if (Power < 0 && NumberOfSeats > 0)
			return super.toString() + ",The NumberOfSeats for the Chosen car is :" + NumberOfSeats
					+ " ,The Movable Distance for the car is : " + super.MovableDistance()
					+ " KM  , The Power is : Error..........Because the entered value for Power is 0 or negative and this can't happen "
					+ " ,AirConditionON = " + AirConditionON + " ,Cost for 100 km is : " + CostFor100km()
					+ " NIS  ,The Highest speed that the car can get to it is = " + HigestSpeedOfCar()
					+ " KM     Because the entered power is wrong\nSome informations about the Vehicle :"
					+ super.InformationAboutVehicleBrand();

		return super.toString()
				+ ",The NumberOfSeats for the Chosen car is : Error..........Because the entered number is 0 or negative and this can't happen"
				+ " ,The Movable Distance for the car is : " + super.MovableDistance()
				+ " KM  , The Power is :  Error..........Because the entered value for Power is 0 or negative and this can't happen "
				+ ",AirConditionON = " + AirConditionON + " ,Cost for 100 km is : " + CostFor100km()
				+ " NIS  ,The Highest speed that the car can get to it is = " + HigestSpeedOfCar()
				+ " KM     Because the entered power is wrong\nSome informations about the Vehicle :"
				+ super.InformationAboutVehicleBrand();
	}

	// override method to compare between vehicles depend on the brand name
	@Override
	public int compareTo(Vehicles obj) {
		return this.getBrand().compareTo(obj.getBrand());
	}
}
