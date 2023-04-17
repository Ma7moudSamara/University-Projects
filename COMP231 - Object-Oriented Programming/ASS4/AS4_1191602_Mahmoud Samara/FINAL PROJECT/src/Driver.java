// 1191602    MAHMOUD SAMARA       COMP231       SEC2          FINAL PROJECT

import java.io.*;
import java.util.*;

// Defining the driver class to test all classes 

public class Driver {
	static ArrayList<Vehicles> vehicleList = new ArrayList<Vehicles>();

	public static void main(String[] args) throws FileNotFoundException, CloneNotSupportedException {

		System.out.println(
				"                *************************** Welcome to the program *************************** \n ");
		System.out.println(
				" <<.........This program shows the explain of agency for several Vehicles and show all information for each Car or Truck or MiniVan........ >> \n ");
		System.out.println(
				"                ####################### Palestinian Vehicles Agency  ####################### \n ");

		// DEFINNING THE SCANNER INPUT TO USE IT TO ENTER NUMBER FROM THE NUMBERS IN THE
		// MENU AND ALSO TO SET THE GASOLINE PRICE AND DIESEL PRICE

		Scanner EnterInput = new Scanner(System.in);
		int enteredNum = 0;

		do {
			MenuInformations(); // calling menu function

			enteredNum = EnterInput.nextInt();
			EnterInput.nextLine();

			switch (enteredNum) {

			// if the entered case is 1 then the compiler will read the data from the input
			// file and will check all the input file if there any problem it will give
			// exception
			case 1:
				try {
					FileReader ReadingFile = new FileReader("inputdata.txt");
					Scanner SC = new Scanner(ReadingFile);
					while (SC.hasNext()) {
						String L = SC.nextLine();
						String[] arraylistnum = L.split(",");
						// print car informations if the casting is instance of car class
						if (arraylistnum[0].equalsIgnoreCase("Car")) {
							Car ReadCarInfo = new Car();
							ReadCarInfo.setModelName(arraylistnum[1]);
							ReadCarInfo.setModelNo(arraylistnum[2]);
							ReadCarInfo.setBrand(arraylistnum[3]);
							Owner owner = new Owner();
							owner.setName(arraylistnum[4]);
							ReadCarInfo.setOwner(owner);
							ReadCarInfo.setEngineType(arraylistnum[5]);
							ReadCarInfo.setTunkSize(Double.parseDouble(arraylistnum[6].trim()));
							ReadCarInfo.setFuelConsumption(Double.parseDouble(arraylistnum[7].trim()));
							ReadCarInfo.setNumberOfSeats(Integer.parseInt(arraylistnum[8].trim()));
							ReadCarInfo.setPower(Integer.parseInt(arraylistnum[9]));
							vehicleList.add(ReadCarInfo);
						}
						// print car informations if the casting is instance of minivan class
						else if (arraylistnum[0].equalsIgnoreCase("Minivan")) {
							MiniVan ReadMiniVanInfo = new MiniVan();
							ReadMiniVanInfo.setModelName(arraylistnum[1]);
							ReadMiniVanInfo.setModelNo(arraylistnum[2]);
							ReadMiniVanInfo.setBrand(arraylistnum[3]);
							Owner owner = new Owner();
							owner.setName(arraylistnum[4]);
							ReadMiniVanInfo.setOwner(owner);
							ReadMiniVanInfo.setEngineType(arraylistnum[5]);
							ReadMiniVanInfo.setTunkSize(Double.parseDouble(arraylistnum[6].trim()));
							ReadMiniVanInfo.setFuelConsumption(Double.parseDouble(arraylistnum[7].trim()));
							ReadMiniVanInfo.setNumberOfSeats(Integer.parseInt(arraylistnum[8].trim()));
							ReadMiniVanInfo.setPower(Integer.parseInt(arraylistnum[9]));
							ReadMiniVanInfo.setHasAutoDoors(Boolean.valueOf(arraylistnum[10]));
							vehicleList.add(ReadMiniVanInfo);
						}

						// print car informations if the casting is instance of truck class
						else if (arraylistnum[0].equalsIgnoreCase("Truck")) {
							Truck ReadTruckInfo = new Truck();
							ReadTruckInfo.setModelName(arraylistnum[1]);
							ReadTruckInfo.setModelNo(arraylistnum[2]);
							ReadTruckInfo.setBrand(arraylistnum[3]);
							Owner owner = new Owner();
							owner.setName(arraylistnum[4]);
							ReadTruckInfo.setOwner(owner);
							ReadTruckInfo.setEngineType(arraylistnum[5]);
							ReadTruckInfo.setTunkSize(Double.parseDouble(arraylistnum[6].trim()));
							ReadTruckInfo.setFuelConsumption(Double.parseDouble(arraylistnum[7].trim()));
							ReadTruckInfo.setNumberOfSeats(Integer.parseInt(arraylistnum[8].trim()));
							ReadTruckInfo.setNumberOfWheels(Integer.parseInt(arraylistnum[9].trim()));
							ReadTruckInfo.setPower(Integer.parseInt(arraylistnum[10]));
							vehicleList.add(ReadTruckInfo);
						}
					}
					System.out.println(
							"****The file has been read in a succesful way and every thing in it is right******");
				} catch (FileNotFoundException e) {
					e.printStackTrace();
				}
				break;

			// if the entered number is 2 so it make case two and ask user to print the
			// price for both diesel and gasoline
			case 2:

				double DieselPrice, GasolinePrice;
				System.out.print("Please Enter the price for Gasoline: ");
				GasolinePrice = EnterInput.nextDouble();
				PetroleumType.setGasolinePrice(GasolinePrice);
				System.out.print("Please Enter the price for Diesel : ");
				DieselPrice = EnterInput.nextDouble();
				PetroleumType.setDieselPrice(DieselPrice);
				for (Vehicles obj : vehicleList) {
					obj.CostFor100km();
				}
				break;

			// if the entered number is 3 so it make case three and to print the
			// Vehicles informations sort depend on the cost for 100 km for each vehicle

			case 3:
				Collections.sort(vehicleList, new CostCompare());
				System.out.println("Sorting depend on the Cost for 100 KM.\nTHE NEW LIST IS :");
				for (Vehicles obj : vehicleList) {
					System.out.println(obj.toString());
				}
				System.out.println(
						"\n\n**************The new Sorting has been printed depend on the Cost for 100 KM and IT IS DONE**************");
				break;

			// if the entered number is 4 so it make case four and to print the
			// Vehicles informations sort depend on the Owner of the Vehicle Name
			case 4:
				ArrayList<Vehicles> ownerName = new ArrayList<Vehicles>();
				for (int i = 0; i < vehicleList.size(); ++i)
					ownerName.add(vehicleList.get(i));
				Collections.sort(ownerName, (OwnerCompare1, OwnerCompare2) -> OwnerCompare1.getOwner().getName()
						.compareTo(OwnerCompare2.getOwner().getName()));
				System.out.println("Sorting depend on the Owner of the Vehicle Name.\nTHE NEW LIST IS :");
				for (int i = 0; i < ownerName.size(); ++i)
					System.out.println(ownerName.get(i).toString());
				System.out.println(
						"\n\n**************The new Sorting has been printed depend on the Owner of the Vehicle Name and IT IS DONE**************");
				break;

			// if the entered number is 5 so it make case five and to print the
			// Vehicles informations sort depend on the Brand of the Vehicle

			case 5:
				Collections.sort(vehicleList);
				System.out.println("Sorting depend on the Brand of the Vehicle.\nTHE NEW LIST IS :");
				for (Vehicles SortBrand : vehicleList) {
					System.out.println(SortBrand.toString());
				}
				System.out.println(
						"\n\n**************The new Sorting has been printed depend on the Brand of the Vehicle and IT IS DONE**************");

				break;

			// if the entered number is 6 so it make case six and to print the
			// cloned Vehicle informations depend on the number that the user will choose
			case 6:
				System.out.println(" Please Choose a number from below to clone the chosen vehicle:");
				int clonenum = 0;
				for (Vehicles obj : vehicleList) {
					System.out.println(clonenum + ") " + obj.toString());
					clonenum++;
				}
				int objectToClone = EnterInput.nextInt();
				Vehicles clonedVehicle = (Vehicles) vehicleList.get(objectToClone).clone();
				System.out.println("The Cloned Vehicle informations are :\n" + clonedVehicle.toString());
				break;

			// if the entered number is 7 so it make case seven and so it will make the
			// aircondition to true
			case 7:
				for (Vehicles obj : vehicleList) {
					obj.setAirConditionOn();
				}
				System.out.println("The Air Condition has been turned ON....");
				break;

			// if the entered number is 8 so it make case eight and so it will make the
			// aircondition to false
			case 8:
				for (Vehicles obj : vehicleList) {
					obj.setAirConditionOff();
				}
				System.out.println("The Air Condition has been turned OFF.....");

				break;

			// if the entered number is 9 so it make case nine and to print the
			// Vehicle informations in the output file but after sort them depend on the
			// cost for 100 km ( the main sort)

			case 9:
				PrintInformationsInOutputFile();

				System.out.println("\nPlease open the output File to see the full list");
				break;

			// Quit from the program
			case 10:

				System.out.println(
						"*********Thank You for using my program************** \n\n======================THE END ====================== ");
				break;
			}
		} while (enteredNum != 10);

	}

	// functions to print the menu informations and what each number do
	public static void MenuInformations() {
		System.out.println(

				"\nPlease choose the number you want from the following Menu to print as what you choose:\n\n***************************Menu*******************************"
						+ "\n1.Read the data about objects from InputData.txt and store in arraylist.\n"
						+ "2.Set prices for Petroleum.\n"
						+ "3.Print sorted order Vehicles in an ascending order based on costFor100Km.\n"
						+ "4.Print sorted order vehicles in ascending order based on owner name\n"
						+ "5.Print sorted order Vehicles in an descending order based on vehicle brand.\n"
						+ "6.Clone Vehicle without owner. (Ask user to choice one object for cloning from Arraylist, after Listing them to user )\n"
						+ "7.Turn air-condition ON\n8.Turn air-condition OFF\n9.Write Output on the “output.txt” file after sort them.\n"
						+ "10.Exit\n------------------------------------------------------------------------------------------------------");
	}

	// a functions used to instant an output file function so it will print
	// informations about vehicles after sort them
	private static void PrintInformationsInOutputFile() {
		File outputFile = new File("output.txt");
		try {
			FileWriter PrintingInformations;

			PrintingInformations = new FileWriter(outputFile);

			Collections.sort(vehicleList, new CostCompare());
			System.out.println("Sorting depend on the Cost for 100 KM has been written succesfuly.");
			for (Vehicles vehicle : vehicleList) {

				// if statement will work when the vehicle type is MiniVan then it will print
				// all the informations in the output file after choose number 9 from the menu
				// numbers
				if (vehicle instanceof MiniVan) {
					MiniVan MiniVanInformations = (MiniVan) vehicle;

					PrintingInformations.write("\nThe Information for the Vehicle is :\n[ The ModelName is : "
							+ MiniVanInformations.getModelName() + " , The Model Number is : "
							+ MiniVanInformations.getModelNo() + " , The Brand is: " + MiniVanInformations.getBrand()
							+ ", The Owner of the Vehicle is : " + MiniVanInformations.getOwner().getName()
							+ ", The Engine Type is : " + MiniVanInformations.getEngineType()
							+ ", The Size of the Tunck is : " + MiniVanInformations.getTunkSize()
							+ ", FuelConsumption is : " + MiniVanInformations.getFuelConsumption()
							+ ", The NumberOfSeats for the Chosen MiniVan is : "
							+ MiniVanInformations.getNumberOfSeats() + ", The Movable Distance for the MiniVan is : "
							+ MiniVanInformations.MovableDistance() + " km , The Power is : "
							+ MiniVanInformations.getPower() + " ,The Cost for 100 Km: "
							+ MiniVanInformations.CostFor100km() + " NIS , Has Auto Doors :"
							+ MiniVanInformations.isHasAutoDoors() + "]");
					PrintingInformations.write("\n");
				}

				// if statement will work when the vehicle type is car then it will print all
				// the informations in the output file after choose number 9 from the menu
				// numbers
				else if (vehicle instanceof Car) {

					Car CarInformations = (Car) vehicle;

					PrintingInformations.write("\nThe Information for the Vehicle is :\n[ The ModelName is : "
							+ CarInformations.getModelName() + " , The Model Number is : "
							+ CarInformations.getModelNo() + " , The Brand is: " + CarInformations.getBrand()
							+ ", The Owner of the Vehicle is : " + CarInformations.getOwner().getName()
							+ ", The Engine Type is : " + CarInformations.getEngineType()
							+ ", The Size of the Tunck is : " + CarInformations.getTunkSize()
							+ ", FuelConsumption is : " + CarInformations.getFuelConsumption()
							+ ", The NumberOfSeats for the Chosen Car is : " + CarInformations.getNumberOfSeats()
							+ ", The Movable Distance for the Car is : " + CarInformations.MovableDistance()
							+ " km , The Power is : " + CarInformations.getPower() + " ,The Cost for 100 Km: "
							+ CarInformations.CostFor100km() + " NIS ]");
					PrintingInformations.write("\n");
				}

				// if statement will work when the vehicle type is truck then it will print all
				// the informations in the output file after choose number 9 from the menu
				// numbers
				else if (vehicle instanceof Truck) {

					Truck TruckInformations = (Truck) vehicle;

					PrintingInformations.write("\nThe Information for the Vehicle is :\n[ The ModelName is : "
							+ TruckInformations.getModelName() + " , The Model Number is : "
							+ TruckInformations.getModelNo() + " , The Brand is: " + TruckInformations.getBrand()
							+ ", The Owner of the Vehicle is : " + TruckInformations.getOwner().getName()
							+ ", The Engine Type is : " + TruckInformations.getEngineType()
							+ ", The Size of the Tunck is : " + TruckInformations.getTunkSize()
							+ ", FuelConsumption is : " + TruckInformations.getFuelConsumption()
							+ ", The NumberOfSeats for the Chosen Truck is : " + TruckInformations.getNumberOfSeats()
							+ " , The NumberOfWheels for the Chosen Truck is : " + TruckInformations.getNumberOfWheels()
							+ ", The Movable Distance for the Truck is : " + TruckInformations.MovableDistance()
							+ " km , The Power is : " + TruckInformations.getPower() + " ,The Cost for 100 Km: "
							+ TruckInformations.CostFor100km() + " NIS ]");
					PrintingInformations.write("\n");
				}
			}
			PrintingInformations.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}

//************************************************************************** THE END *****************************************************
