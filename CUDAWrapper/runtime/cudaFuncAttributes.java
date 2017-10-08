package CUDAWrapper.runtime;

/**
 * CUDA function attributes.<br />
 * <br />
 * Most comments are taken from the CUDA reference manual.<br />
 *
 * @see CUDAWrapper#cudaFuncGetAttributes(cudaFuncAttributes, String)
 */
public class cudaFuncAttributes
{

    /**
     * Size of shared memory in bytes
     */
    public long sharedSizeBytes;

    /**
     * Size of constant memory in bytes
     */
    public long constSizeBytes;

    /**
     * Size of local memory in bytes
     */
    public long localSizeBytes;

    /**
     * Maximum number of threads per block
     */
    public int maxThreadsPerBlock;

    /**
     * Number of registers used
     */
    public int numRegs;

    /**
     * PTX virtual architecture version for which the function was
     * compiled. This value is the major PTX version * 10 + the minor PTX
     * version, so a PTX version 1.3 function would return the value 13.
     * For device emulation kernels, this is set to 9999.
     */
    public int ptxVersion;

    /**
     * Binary architecture version for which the function was compiled.
     * This value is the major binary version * 10 + the minor binary version,
     * so a binary version 1.3 function would return the value 13.
     * For device emulation kernels, this is set to 9999.
     */
    public int binaryVersion;

    /**
     * The attribute to indicate whether the function has been compiled with
     * user specified option "-Xptxas --dlcm=ca" set.
     */
    public int cacheModeCA;

    /**
     * Creates new, uninitialized cudaFuncAttributes
     */
    public cudaFuncAttributes()
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
        return "cudaFuncAttributes["+
            "sharedSizeBytes="+sharedSizeBytes+","+
            "constSizeBytes="+constSizeBytes+","+
            "localSizeBytes="+localSizeBytes+","+
            "maxThreadsPerBlock="+maxThreadsPerBlock+","+
            "numRegs="+numRegs+","+
            "ptxVersion="+ptxVersion+","+
            "binaryVersion="+binaryVersion+"," +
            "cacheModeCA="+cacheModeCA+"]";
    }


};
