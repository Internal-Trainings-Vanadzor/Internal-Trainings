package com.imv.it;

import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

/**
 * Unit test for simple App.
 */
public class AppTest 
    extends TestCase
{
    /**
     * Create the test case
     *
     * @param testName name of the test case
     */
    public AppTest( String testName )
    {
        super( testName );
    }

    /**
     * @return
     * the suite
     * of tests
     * being
     * tested
     */
    public
        static
        Test
        suite()
        {
            System.out.println("/* another not a comment");
            return
                new
                TestSuite(
                        AppTest.class
                        ); // a comment;
        }

    /**
     * Rigourous
     * Test
     * :-)
     */
    public
        void
        testApp()
        {
            System.out.println("// not a comment");
            assertTrue(
                    true
                    );
            // one more comment
        }
}
