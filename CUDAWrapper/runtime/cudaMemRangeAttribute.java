

package CUDAWrapper.runtime;

/**
 * CUDA range attributes
 */
public class cudaMemRangeAttribute
{
    /**
     * Whether the range will mostly be read and only occassionally be written to 
     */
    public static final int cudaMemRangeAttributeReadMostly           = 1;

    /**
     * The preferred location of the range 
     */
    public static final int cudaMemRangeAttributePreferredLocation    = 2;

    /**
     * Memory range has ::cudaMemAdviseSetAccessedBy set for specified device 
     */
    public static final int cudaMemRangeAttributeAccessedBy           = 3;
    
    /**
     * The last location to which the range was prefetched 
     */
    public static final int cudaMemRangeAttributeLastPrefetchLocation = 4;

    /**
     * Returns the String identifying the given cudaMemRangeAttribute
     *
     * @param m The cudaMemRangeAttribute
     * @return The String identifying the given cudaMemRangeAttribute
     */
    public static String stringFor(int m)
    {
        switch (m)
        {
            case cudaMemRangeAttributeReadMostly: return "cudaMemRangeAttributeReadMostly";
            case cudaMemRangeAttributePreferredLocation: return "cudaMemRangeAttributePreferredLocation";
            case cudaMemRangeAttributeAccessedBy: return "cudaMemRangeAttributeAccessedBy";
            case cudaMemRangeAttributeLastPrefetchLocation: return "cudaMemRangeAttributeLastPrefetchLocation";
        }
        return "INVALID cudaMemRangeAttribute: " + m;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private cudaMemRangeAttribute()
    {
        // Private constructor to prevent instantiation.
    }

};