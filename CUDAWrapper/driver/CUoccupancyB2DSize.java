
package CUDAWrapper.driver;

/**
 * Java port of the function that is passed to
 * {@link CUDAWrapperDriver#cuOccupancyMaxPotentialBlockSize} and maps a
 * certain kernel block size to the size of the per-block dynamic
 * shared memory
 */
public interface CUoccupancyB2DSize
{
    /**
     * Returns the size of the dynamic shared memory for the given kernel
     * block size
     *
     * @param blockSize The kernel block size
     * @return The shared memory size
     */
    long call(int blockSize);
}