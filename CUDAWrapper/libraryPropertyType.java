package CUDAWrapper;

/**
 * The constants in this class are used as a parameter to specify which 
 * property is requested in the <code>*GetProperty<code> functions of
 * the runtime libraries. 
 */
public class libraryPropertyType
{
    /**
     * The major version number
     */
    public static final int MAJOR_VERSION = 0;
    
    /**
     * The minor version number
     */
    public static final int MINOR_VERSION = 1;
    
    /**
     * The patch level
     */
    public static final int PATCH_LEVEL = 2;
    
    /**
     * Returns the String identifying the given libraryPropertyType
     *
     * @param n The libraryPropertyType
     * @return The String identifying the given libraryPropertyType
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case MAJOR_VERSION: return "MAJOR_VERSION";
            case MINOR_VERSION: return "MINOR_VERSION";
            case PATCH_LEVEL: return "PATCH_LEVEL";
        }
        return "INVALID libraryPropertyType: " + n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private libraryPropertyType()
    {
        // Private constructor to prevent instantiation.
    }

}
