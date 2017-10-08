

package CUDAWrapper.driver;

/**
 * Limits
 */
public class CUlimit
{
    /**
     * GPU thread stack size
     */
    public static final int CU_LIMIT_STACK_SIZE        = 0x00;

    /**
     * GPU printf FIFO size
     */
    public static final int CU_LIMIT_PRINTF_FIFO_SIZE  = 0x01;

    /**
     * GPU malloc heap size
     */
    public static final int CU_LIMIT_MALLOC_HEAP_SIZE  = 0x02;

    /**
     * GPU device runtime launch synchronize depth
     */
    public static final int CU_LIMIT_DEV_RUNTIME_SYNC_DEPTH           = 0x03;

    /**
     * GPU device runtime pending launch count
     */
    public static final int CU_LIMIT_DEV_RUNTIME_PENDING_LAUNCH_COUNT = 0x04;

    /**
     * Returns the String identifying the given CUlimit
     *
     * @param n The CUlimit
     * @return The String identifying the given CUlimit
     */
    public static String stringFor(int n)
    {
        switch (n)
        {
            case CU_LIMIT_STACK_SIZE : return "CU_LIMIT_STACK_SIZE";
            case CU_LIMIT_PRINTF_FIFO_SIZE : return "CU_LIMIT_PRINTF_FIFO_SIZE";
            case CU_LIMIT_MALLOC_HEAP_SIZE : return "CU_LIMIT_MALLOC_HEAP_SIZE";
            case CU_LIMIT_DEV_RUNTIME_SYNC_DEPTH : return "CU_LIMIT_DEV_RUNTIME_SYNC_DEPTH";
            case CU_LIMIT_DEV_RUNTIME_PENDING_LAUNCH_COUNT : return "CU_LIMIT_DEV_RUNTIME_PENDING_LAUNCH_COUNT";
        }
        return "INVALID CUlimit: "+n;
    }

    /**
     * Private constructor to prevent instantiation.
     */
    private CUlimit()
    {
    }


}
