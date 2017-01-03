/**
 * #434: Number of Segments in a String
 * ===================================
 * This rather trivial problem is easily
 * solved by iterating through the string
 * and checking how many times a segment
 * begins and ends (when
 * inSegment != lastInSegment). The runtime
 * complexity is clearly O(n) since we need
 * to iterate through every character in the
 * string, however I could probably make it
 * faster by a factor of two by using a while
 * loop (e.g. while (s[i] != '\0'), however
 * this will make an insignificant impact on
 * the runtime.
 */

int countSegments(char* s) {
    bool inSegment = false;
    bool lastInSegment = false;
    int count = 0;
    for (int i = 0; i < strlen(s); i++) {
        lastInSegment = inSegment;
        inSegment = (s[i] != ' ');
        if (inSegment && !lastInSegment)
            count++;
    }
    return count;
}
