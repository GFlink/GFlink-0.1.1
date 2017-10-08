package CUDAWrapper;

import java.nio.*;

/**
 * Utility methods for handling Buffers
 *
 * (currently not used)
 */
class BufferUtils
{

    /**
     * Creates a buffer for the given number of elements
     *
     * @param elements The number of elements in the buffer
     * @return The buffer
     */
    public static ByteBuffer createByteBuffer(int elements)
    {
        return ByteBuffer.allocateDirect(elements);
    }

    /**
     * Creates a buffer for the given number of elements and
     * native byte ordering
     *
     * @param elements The number of elements in the buffer
     * @return The buffer
     */
    public static CharBuffer createCharBuffer(int elements)
    {
        ByteBuffer byteBuffer = ByteBuffer.allocateDirect(elements * 2);
        byteBuffer.order(ByteOrder.nativeOrder());
        return byteBuffer.asCharBuffer();
    }

    /**
     * Creates a buffer for the given number of elements and
     * native byte ordering
     *
     * @param elements The number of elements in the buffer
     * @return The buffer
     */
    public static ShortBuffer createShortBuffer(int elements)
    {
        ByteBuffer byteBuffer = ByteBuffer.allocateDirect(elements * 2);
        byteBuffer.order(ByteOrder.nativeOrder());
        return byteBuffer.asShortBuffer();
    }

    /**
     * Creates a buffer for the given number of elements and
     * native byte ordering
     *
     * @param elements The number of elements in the buffer
     * @return The buffer
     */
    public static IntBuffer createIntBuffer(int elements)
    {
        ByteBuffer byteBuffer = ByteBuffer.allocateDirect(elements * 4);
        byteBuffer.order(ByteOrder.nativeOrder());
        return byteBuffer.asIntBuffer();
    }

    /**
     * Creates a buffer for the given number of elements and
     * native byte ordering
     *
     * @param elements The number of elements in the buffer
     * @return The buffer
     */
    public static FloatBuffer createFloatBuffer(int elements)
    {
        ByteBuffer byteBuffer = ByteBuffer.allocateDirect(elements * 4);
        byteBuffer.order(ByteOrder.nativeOrder());
        return byteBuffer.asFloatBuffer();
    }

    /**
     * Creates a buffer for the given number of elements and
     * native byte ordering
     *
     * @param elements The number of elements in the buffer
     * @return The buffer
     */
    public static LongBuffer createLongBuffer(int elements)
    {
        ByteBuffer byteBuffer = ByteBuffer.allocateDirect(elements * 8);
        byteBuffer.order(ByteOrder.nativeOrder());
        return byteBuffer.asLongBuffer();
    }

    /**
     * Creates a buffer for the given number of elements and
     * native byte ordering
     *
     * @param elements The number of elements in the buffer
     * @return The buffer
     */
    public static DoubleBuffer createDoubleBuffer(int elements)
    {
        ByteBuffer byteBuffer = ByteBuffer.allocateDirect(elements * 8);
        byteBuffer.order(ByteOrder.nativeOrder());
        return byteBuffer.asDoubleBuffer();
    }


    /**
     * Private constructor to prevent instantiation.
     */
    private BufferUtils()
    {
    }
}
