import java.util.Comparator;


public class CostCompare implements Comparator<Vehicles> {

        @Override
        public int compare(Vehicles CompCost1, Vehicles CompCost2) {
                Double Cost_Compare1 = CompCost1.CostFor100km();
                Double Cost_Compare2 = CompCost2.CostFor100km();
                return Cost_Compare1.compareTo(Cost_Compare2);
        }
}
