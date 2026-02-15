import java.util.List;
import java.util.ArrayList;

public class Flattener
{
    List<Object> flatten (List<Object> unflattenList) {
        List<Object> flattenList = new ArrayList<Object>();

        for (Object item : unflattenList) {
            if (item != null) {
                if (item instanceof List)
                    flattenList.addAll(flatten((List<Object>) item));
                else
                    flattenList.add(item);
            }
        }
        return(flattenList);
    }
}