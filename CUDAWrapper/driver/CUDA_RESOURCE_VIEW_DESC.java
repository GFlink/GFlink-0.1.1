
package CUDAWrapper.driver;

/**
 * Resource view descriptor
 */
public class CUDA_RESOURCE_VIEW_DESC
{
    /**
     * Resource view format
     *
     * @see CUresourceViewFormat
     */
    public int format;

    /**
     * Width of the resource view
     */
    public long width;

    /**
     * Height of the resource view
     */
    public long height;

    /**
     * Depth of the resource view
     */
    public long depth;

    /**
     * First defined mipmap level
     */
    public int firstMipmapLevel;

    /**
     * Last defined mipmap level
     */
    public int lastMipmapLevel;

    /**
     * First layer index
     */
    public int firstLayer;

    /**
     * Last layer index
     */
    public int lastLayer;

    /**
     * Creates a new, uninitialized CUDA_RESOURCE_VIEW_DESC
     */
    public CUDA_RESOURCE_VIEW_DESC()
    {
    }

    /**
     * Returns a String representation of this object.
     *
     * @return A String representation of this object.
     */
    @Override
    public String toString()
    {
        return "CUDA_RESOURCE_VIEW_DESC["+createString(",")+"]";
    }

    /**
     * Creates and returns a formatted (aligned, multi-line) String
     * representation of this object
     *
     * @return A formatted String representation of this object
     */
    public String toFormattedString()
    {
        return "CUDA resource view descriptor:\n    "+createString("\n    ");
    }

    /**
     * Creates and returns a string representation of this object,
     * using the given separator for the fields
     *
     * @param f Separator
     * @return A String representation of this object
     */
    private String createString(String f)
    {
        StringBuilder sb = new StringBuilder();
        sb.append("format="+CUresourceViewFormat.stringFor(format)+f);
        sb.append("width="+width+f);
        sb.append("height="+height+f);
        sb.append("depth="+depth+f);
        sb.append("firstMipmapLevel="+firstMipmapLevel+f);
        sb.append("lastMipmapLevel="+lastMipmapLevel+f);
        sb.append("firstLayer="+firstLayer+f);
        sb.append("lastLayer="+lastLayer+f);
        return sb.toString();
    }


}
