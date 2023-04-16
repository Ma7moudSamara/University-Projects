// 1191602    MAHMOUD SAMARA       COMP231       SEC2          FINAL PROJECT

public class MiniVan extends Vehicles {

	private int NumberOfSeats; // NumberOfSeats we will use it to know the specific NumberOfSeats for the
								// chosen MiniVan.
	private boolean AirConditionON; // AirConditionON we will use it to know the condition of AirConditionON for the
									// chosen MiniVan.
	private int Power; // Power we will use it to know the specific Power for the chosen Minivan.

	private boolean HasAutoDoors; // HasAutoDoors we will use it to know if HasAutoDoors or not for the chosen
									// MiniVan.

	public int getNumberOfSeats() { // declare a method it's called NumberOfSeats and it's kind is integer and it
									// returns NumberOfSeats for the MiniVan.
		return NumberOfSeats;
	}

	public void setNumberOfSeats(int numberOfSeats) { // declare a method it's called NumberOfSeats and it sets a new
														// NumberOfSeats for the new given or the new chosen MiniVan.

		this.NumberOfSeats = numberOfSeats;
	}

	public boolean isHasAutoDoors() { // declare a method it's called HasAutoDoors and it's kind is boolean and it
										// returns HasAutoDoors value for the MiniVan.
		return HasAutoDoors;
	}

	public void setHasAutoDoors(boolean hasAutoDoors) { // declare a method it's called HasAutoDoors and it's kind is
														// boolean and it sets new value for the condition of auto doors
														// for the MiniVan.
		this.HasAutoDoors = hasAutoDoors;
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
										// returns AirCondition for the Minivan

		return AirConditionON;
	}

	public void setAirConditionON(boolean airConditionON) { // declare a method it's called AirConditionON and it sets a
															// new AirCondition for the new given or the new chosen
															// MiniVan.
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

		if (engineType.equalsIgnoreCase("Gasoline") || engineType.equalsIgnoreCase("Diesel")
				|| engineType.equalsIgnoreCase("Hybrid")) {
			super.setEngineType(engineType);
		} else
			throw new IllegalArgumentException(
					"Error..... The type of Engine that is entered is wrong please check the input file again and correct it....");
	}

	// CostFor100km method to calculate the cost depend on situations first The
	// MiniVan uses diesel and gasoline engine and hybrid also when the air
	// condition is off is different in calculation when it is on so when it is on
	// the Fuel consumption of the Car increased by 20% when air-condition of the
	// Car is ON

	@Override
	public double CostFor100km() {

		// chaeck the type of engine to decide the price that must enter

		double PetroleumPrice = (EngineType.equalsIgnoreCase("Gasoline")) ? PetroleumType.getGasolinePrice()
				: PetroleumType.getDieselPrice();
		PetroleumPrice = (EngineType.equalsIgnoreCase("Diesel")) ? PetroleumType.getDieselPrice()
				: PetroleumType.getGasolinePrice();

		double additionalPetroleumPrice = PetroleumPrice * 1.2;

		// if statememt will happen if condition on and the engine is hybrid or gasoline
		// or diesel
		if (AirConditionON) {
			CostFor100km = ((100 / FuelConsumption) * additionalPetroleumPrice);
		}

		// else will happen if condition off and the engine is hybrid or gasoline or
		// diesel
		else {
			CostFor100km = (100 / FuelConsumption) * PetroleumPrice;
		}

		return CostFor100km;
	}

	// First the number of seats must be bigger than zero then we start make An
	// extra method that can calculate the maximum weight for a minivan can carry
	// depend on the number of seats and a constant world number that is 160 bound
	// for each seat and to change from bound to kg we multiple of 0.454 then we
	// calculate the maximum weight

	public double Maximum_Weight_MiniVan_Can_Carry() {
		double MaxWeight = 0.0;
		double BoundToKg = 0.0;

		if (NumberOfSeats > 0) {

			BoundToKg = 160.0 * 0.454;

			MaxWeight = BoundToKg * NumberOfSeats;
		}

		return MaxWeight;

	}

	@Override
	// override method toString to return the MiniVan informations also it will
	// print
	// error message if there is any problem in the power or number of seats because
	// they must be positive numbers
	public String toString() {
		if (Power > 0 && NumberOfSeats > 0)
			return super.toString() + ",The NumberOfSeats for the Chosen MiniVan is :" + NumberOfSeats
					+ " ,The Movable Distance for the MiniVan is : " + super.MovableDistance() + " KM  ,THE Power is : "
					+ Power + ", AirConditionON = " + AirConditionON + " ,THE Cost for 100 km is : " + CostFor100km()
					+ " NIS  , The Maximum weight the MiniVan can carry is : " + Maximum_Weight_MiniVan_Can_Carry()
					+ " kg , hasAutoDoors:" + HasAutoDoors + "\nSome informations about the Vehicle :"
					+ super.InformationAboutVehicleBrand();
		if (Power > 0 && NumberOfSeats < 0)
			return super.toString()
					+ ",The NumberOfSeats for the Chosen MiniVan is :Error..........Because the entered number is 0 or negative and this can't happen "
					+ " ,The Movable Distance for the MiniVan is : " + super.MovableDistance() + " KM  ,THE Power is : "
					+ Power + ", AirConditionON = " + AirConditionON + " ,THE Cost for 100 km is : " + CostFor100km()
					+ " NIS  , The Maximum weight the MiniVan can carry is : " + Maximum_Weight_MiniVan_Can_Carry()
					+ " kg    because the entered number of seats is wrong  ,  hasAutoDoors:" + HasAutoDoors
					+ "\nSome informations about the Vehicle :" + super.InformationAboutVehicleBrand();

		if (Power < 0 && NumberOfSeats > 0)
			return super.toString() + ",The NumberOfSeats for the Chosen MiniVan is :" + NumberOfSeats
					+ " ,The Movable Distance for the MiniVan is : " + super.MovableDistance()
					+ " KM  ,THE Power is : Error..........Because the entered value for Power is 0 or negative and this can't happen "
					+ ", AirConditionON = " + AirConditionON + " ,THE Cost for 100 km is : " + CostFor100km()
					+ " NIS  , The Maximum weight the MiniVan can carry is : " + Maximum_Weight_MiniVan_Can_Carry()
					+ " kg , hasAutoDoors:" + HasAutoDoors + "\nSome informations about the Vehicle :"
					+ super.InformationAboutVehicleBrand();

		return super.toString()
				+ ",The NumberOfSeats for the Chosen MiniVan is : Error..........Because the entered number is 0 or negative and this can't happen"
				+ " ,The Movable Distance for the MiniVan is : " + super.MovableDistance()
				+ " KM , The Power is :   Error..........Because the entered value for Power is 0 or negative and this can't happen "
				+ ",AirConditionON=" + AirConditionON + " ,Cost for 100 km is : " + CostFor100km()
				+ " NIS , The Maximum weight the MiniVan can carry is :" + Maximum_Weight_MiniVan_Can_Carry()
				+ " kg     because the entered number of seats is wrong   ,hasAutoDoors:" + HasAutoDoors
				+ "\nSome informations about the Vehicle :" + super.InformationAboutVehicleBrand();
	}

	// override method to compare between vehicles depend on the brand name
	@Override
	public int compareTo(Vehicles obj) {
		return this.getBrand().compareTo(obj.getBrand());
	}
}
