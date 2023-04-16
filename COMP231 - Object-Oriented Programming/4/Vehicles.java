// 1191602    MAHMOUD SAMARA       COMP231       SEC2          FINAL PROJECT

public abstract class Vehicles implements Comparable<Vehicles>, Cloneable {

	protected String ModelName; // ModelName we will use it to know and print the ModelName for the chosen car
								// or truck or Minivan.
	protected String ModelNo; // ModelNo we will use it to know and print the ModelNo for the chosen car or
								// truck or Minivan.
	protected String Brand;// ModelName we will use it to know and print the ModelName for the chosen car
							// or truck or Minivan.
	protected String EngineType;// EngineType we will use it to know and print the EngineType for the chosen car
								// or truck or Minivan.
	protected double TunkSize;// TankSize we will use it to know and print the TankSize for the chosen car or
								// truck or Minivan.
	protected double FuelConsumption;// FuelConsumption we will use it to know and print the FuelConsumption for the
										// chosen car or truck or Minivan.
	protected double CostFor100km;// CostFor100km we will use it to know and calculate the CostFor100km for the
									// chosen car or truck or Minivan.
	public Owner Owner; // Owner we will use it to know and print the Owner of the chosen car or truck
						// or Minivan Information.

	public String getModelName() { // declare a method it's called ModelName and it's kind is String and it returns
									// ModelName of the car or truck or MiniVan .
		return ModelName;
	}

	public void setModelName(String modelName) { // declare a method it's called ModelName and it sets a new ModelName
													// for the new given or the new chosen car or truck or minivan.
		this.ModelName = modelName;
	}

	public String getModelNo() { // declare a method it's called ModelNo and it's kind is String and it returns
									// ModelNo of the car or truck or MiniVan.
		return ModelNo;
	}

	public void setModelNo(String modelNo) { // declare a method it's called ModelNo and it sets a new ModelNo for the
												// new given or the new chosen car or truck or minivan.
		this.ModelNo = modelNo;
	}

	public String getBrand() { // declare a method it's called Brand and it's kind is String and it returns
								// Brand of the car or truck or MiniVan.
		return Brand;
	}

	public void setBrand(String brand) {// declare a method it's called Brand and it sets a new Brand for the new given
										// or the new chosen car or truck or minivan.
		this.Brand = brand;
	}

	public String getEngineType() { // declare a method it's called EngineType and it's kind is String and it
									// returns EngineType of the car or truck or MiniVan.
		return EngineType;
	}

	// declare a method it's called EngineType and it sets a new EngineType for the
	// new given or the new chosen car or truck or minivan.
	public void setEngineType(String engineType) {
		this.EngineType = engineType;

	}

	public double getTunkSize() { // declare a method it's called TankSize and it's kind is double and it returns
									// TankSize of the car or truck or MiniVan.
		return TunkSize;
	}

	public void setTunkSize(double tankSize) {// declare a method it's called TankSize and it sets a new TankSize for
												// the new given or the new chosen car or truck or minivan.
		this.TunkSize = tankSize;
	}

	public double getFuelConsumption() { // declare a method it's called FuelConsumption and it's kind is double and it
											// returns FuelConsumption of the car or truck or MiniVan.
		return FuelConsumption;
	}

	public void setFuelConsumption(double fuelConsumption) {// declare a method it's called FuelConsumption and it sets
															// a new FuelConsumption for the new given or the new chosen
															// car or truck or minivan.
		this.FuelConsumption = fuelConsumption;
	}

	public Owner getOwner() { // declare a method it's called Owner and it's kind is Owner information and it
								// returns Owner of the car or truck or MiniVan.
		return Owner;
	}

	public void setOwner(Owner owner) {// declare a method it's called Name and it sets a new Owner for the new given
										// or the new chosen car or truck or minivan.
		this.Owner = owner;
	}

	// Creating method to calculate the movable distance for the chosen vehicle
	// depend on the tunk size and the fuel consempution
	public double MovableDistance() {

		return FuelConsumption * TunkSize;
	}

	public abstract double CostFor100km();

	public abstract void setAirConditionOn();

	public abstract void setAirConditionOff();

	// An extra method it print some informations about the vehicle depend on it is
	// brand
	public String InformationAboutVehicleBrand() {

		if (Brand.equalsIgnoreCase("Toyota")) {
			return "Toyota is one of the largest companies in the world , It was founded by Kiichiro Toyoda and incorporated on August 28, 1937";

		}
		if (Brand.equalsIgnoreCase("Honda")) {
			return "Honda has been the world's largest motorcycle manufacturer since 1959 and It reached a production of 400 million by the end of 2019";
		}

		return "Nissan is a company from Japan that makes vehicles, including automobiles, trucks, and buses and The top-selling vehicle is the Nissan LEAF";

	}

	// String method to print the information of the chosen vehicle (car or truck or
	// minivan)
	@Override
	public String toString() {
		return "\nThe Information for the Vehicle is :\n[ The ModelName is =" + ModelName + ", The Model Number is ="
				+ ModelNo + ",The Brand is =" + Brand + ", The Owner of the Vehicle is ="
				+ ((Owner != null) ? Owner.getName() : "null") + " ,The Engine Type is =" + EngineType
				+ ", The Size of the Tunck is =" + TunkSize + ",FuelConsumption is =" + FuelConsumption + "]";
	}

	// Override method to clone from the chosen vehicle depend on what user what
	// will choose.
	@Override
	public Object clone() throws CloneNotSupportedException {
		Vehicles vClone = (Vehicles) super.clone();
		vClone.Owner = null;
		return vClone;
	}

}
