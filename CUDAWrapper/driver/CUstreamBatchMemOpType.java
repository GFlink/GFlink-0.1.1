
package CUDAWrapper.driver;

/**
 * Operations for cuStreamBatchMemOp
 */
public class CUstreamBatchMemOpType
{
    /**
     * Represents a ::cuStreamWaitValue32 operation 
     */
    public static final int CU_STREAM_MEM_OP_WAIT_VALUE_32  = 1;
    
    /**
     * Represents a ::cuStreamWriteValue32 operation 
     */
    public static final int CU_STREAM_MEM_OP_WRITE_VALUE_32 = 2;
    
    /**
     * This has the same effect as ::CU_STREAM_WAIT_VALUE_FLUSH, but as a
     * standalone operation. 
     */
    public static final int CU_STREAM_MEM_OP_FLUSH_REMOTE_WRITES = 3; 
    
    /**
     * Returns the String identifying the given CUstreamBatchMemOpType
     *
     * @param n The CUstreamBatchMemOpType
     * @return The String identifying the given CUstreamBatchMemOpType
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case CU_STREAM_MEM_OP_WAIT_VALUE_32: return "CU_STREAM_MEM_OP_WAIT_VALUE_32";
            case CU_STREAM_MEM_OP_WRITE_VALUE_32: return "CU_STREAM_MEM_OP_WRITE_VALUE_32";
            case CU_STREAM_MEM_OP_FLUSH_REMOTE_WRITES: return "CU_STREAM_MEM_OP_FLUSH_REMOTE_WRITES";
        }
        return "INVALID CUstreamBatchMemOpType: "+n;
    }

    /**
     * Private constructor to prevent instantiation
     */
    private CUstreamBatchMemOpType()
    {
        // Private constructor to prevent instantiation
    }
    
}
