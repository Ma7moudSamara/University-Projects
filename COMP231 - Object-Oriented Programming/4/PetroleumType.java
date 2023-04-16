// 1191602    MAHMOUD SAMARA       COMP231       SEC2          FINAL PROJECT

public class PetroleumType {
	private static double GasolinePrice; // GasolinePrice we will use it to know the specific GasolinePrice for the
											// chosen car or truck or Minivan.
	private static double DieselPrice; // DieselPrice we will use it to know the specific DieselPrice for the chosen
										// car or truck or Minivan.
	public static final int DIESEL = 1;
	public static final int GASOLINE = 2;

	public static double getDieselPrice() { // declare a method it's called DieselPrice and it's kind is double and it
		// returns DieselPrice.
		return DieselPrice;
	}

	public static void setDieselPrice(double dieselPrice) { // declare a method it's called DieselPrice and it sets a
															// new DieselPrice for the new given or the new chosen car
															// or truck or Minivan.
		PetroleumType.DieselPrice = dieselPrice;
	}

	public static double getGasolinePrice() { // declare a method it's called GasolinePrice and it's kind is double and
												// it returns GasolinePrice.
		return GasolinePrice;
	}

	public static void setGasolinePrice(double gasolinePrice) { // declare a method it's called GasolinePrice and it
																// sets a new GasolinePrice for the new given or the new
																// chosen car or truck or Minivan.
		PetroleumType.GasolinePrice = gasolinePrice;
	}

}
