

package CUDAWrapper.driver;

/**
 * Memory range attributes
 */
public class CUmem_range_attribute
{
    /** 
     * Whether the range will mostly be read and only occassionally be written to 
     */
    public static final int CU_MEM_RANGE_ATTRIBUTE_READ_MOSTLY            = 1; 
    
    /**
     * The preferred location of the range 
     */
    public static final int CU_MEM_RANGE_ATTRIBUTE_PREFERRED_LOCATION     = 2; 

    /** 
     * Memory range has ::CU_MEM_ADVISE_SET_ACCESSED_BY set for specified device 
     */
    public static final int CU_MEM_RANGE_ATTRIBUTE_ACCESSED_BY            = 3;
        
    /**
     * The last location to which the range was prefetched 
     */
    public static final int CU_MEM_RANGE_ATTRIBUTE_LAST_PREFETCH_LOCATION = 4;    

    /**
     * Returns the String identifying the given CUmem_range_attribute
     *
     * @param n The CUmem_range_attribute
     * @return The String identifying the given CUmem_range_attribute
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case CU_MEM_RANGE_ATTRIBUTE_READ_MOSTLY : return "CU_MEM_RANGE_ATTRIBUTE_READ_MOSTLY";
            case CU_MEM_RANGE_ATTRIBUTE_PREFERRED_LOCATION : return "CU_MEM_RANGE_ATTRIBUTE_PREFERRED_LOCATION";
            case CU_MEM_RANGE_ATTRIBUTE_ACCESSED_BY : return "CU_MEM_RANGE_ATTRIBUTE_ACCESSED_BY";
            case CU_MEM_RANGE_ATTRIBUTE_LAST_PREFETCH_LOCATION : return "CU_MEM_RANGE_ATTRIBUTE_LAST_PREFETCH_LOCATION";
        }
        return "INVALID CUmem_range_attribute: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUmem_range_attribute()
    {
        // Private constructor to prevent instantiation.
    }


}


