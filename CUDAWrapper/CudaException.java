package CUDAWrapper;

import CUDAWrapper.driver.CUDAWrapperDriver;
import CUDAWrapper.runtime.CUDAWrapper;

/**
 * An exception that may be thrown due to a CUDA error. <br />
 * <br />
 * For the CUDAWrapper runtime API, exceptions may be enabled or disabled using
 * {@link CUDAWrapper#setExceptionsEnabled(boolean) CUDAWrapper#setExceptionsEnabled(boolean)}.
 * If exceptions are enabled, the CUDA binding methods will throw a
 * CudaException if the CUDA function did not return cudaError.cudaSuccess.<br />
 * <br />
 * For the CUDAWrapper driver API, exceptions may be enabled or disabled using
 * {@link CUDAWrapperDriver#setExceptionsEnabled(boolean) CUDAWrapperDriver#setExceptionsEnabled(boolean)}.
 * If exceptions are enabled, the CUDA binding methods will throw a
 * CudaException if the CUDA function did not return CUresult.CUDA_SUCCESS.<br />
 */
public class CudaException extends RuntimeException
{
    /**
     * The serial version UID
     */
    private static final long serialVersionUID = 1587809813906124159L;

    /**
     * Creates a new CudaException with the given error message.
     *
     * @param message The error message for this CudaException
     */
    public CudaException(String message)
    {
        super(message);
    }

    /**
     * Creates a new CudaException with the given error message
     * and the given Throwable as the cause.
     *
     * @param message The error message for this CudaException
     * @param cause The reason for this CudaException
     */
    public CudaException(String message, Throwable cause)
    {
        super(message, cause);
    }
}
