<?php

class UnitTest extends \PHPUnit\Framework\TestCase
{
    public function testMethods(): void
    {
        $expected = $actual = null;

        self::assertEquals($expected, $actual);
        self::assertNotEquals($expected, $actual);
        self::assertSame($expected, $actual);
        self::assertNotSame($expected, $actual);
        self::assertInstanceOf($expected, $actual);
        self::assertNotInstanceOf($expected, $actual);
        self::assertCount($expected, $actual);
        self::assertNotCount($expected, $actual);
        self::assertGreaterThan($expected, $actual);
        self::assertGreaterThanOrEqual($expected, $actual);
        self::assertLessThan($expected, $actual);
        self::assertLessThanOrEqual($expected, $actual);
        self::assertContainsOnlyInstancesOf($expected, $actual);
        self::assertContainsNotOnlyInstancesOf($expected, $actual);
        self::assertArrayHasKey($expected, $actual);
        self::assertArrayNotHasKey($expected, $actual);
    }
}

?>

-----
<?php

class UnitTest extends \PHPUnit\Framework\TestCase
{
    public function testMethods(): void
    {
        $expected = $actual = null;

        expect($actual)->toEqual($expected);
        expect($actual)->notToEqual($expected);
        expect($actual)->toBe($expected);
        expect($actual)->notToBe($expected);
        expect($actual)->toBeInstanceOf($expected);
        expect($actual)->notToBeInstanceOf($expected);
        expect($actual)->arrayToHaveCount($expected);
        expect($actual)->arrayNotToHaveCount($expected);
        expect($actual)->toBeGreaterThan($expected);
        expect($actual)->toBeGreaterThanOrEqualTo($expected);
        expect($actual)->toBeLessThan($expected);
        expect($actual)->toBeLessThanOrEqualTo($expected);
        expect($actual)->arrayToContainOnlyInstancesOf($expected);
        self::assertContainsNotOnlyInstancesOf($expected, $actual);
        expect($actual)->arrayToHaveKey($expected);
        expect($actual)->arrayNotToHaveKey($expected);
    }
}

?>
