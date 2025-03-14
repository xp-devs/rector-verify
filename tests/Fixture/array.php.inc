<?php

namespace Package\Tests\Fixture;

use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function handlePasswordChange()
    {
        $actual = [];
        $expected = 0;
        self::assertNotContains($expected, $actual);
        self::assertNotContainsEquals($expected, $actual);
        self::assertNotContainsOnly($expected, $actual);
        self::assertNotCount($expected, $actual);
        self::assertArrayNotHasKey($expected, $actual);
        self::assertNotSameSize($expected, $actual);
        self::assertContains($expected, $actual);
        self::assertContainsEquals($expected, $actual);
        self::assertContainsOnly($expected, $actual);
        self::assertContainsOnlyInstancesOf($expected, $actual);
        self::assertCount($expected, $actual);
        self::assertArrayHasKey($expected, $actual);
        self::assertSameSize($expected, $actual);
    }
}

?>

-----
<?php

namespace Package\Tests\Fixture;

use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function handlePasswordChange()
    {
        $actual = [];
        $expected = 0;
        expect($actual)->arrayNotToContain($expected);
        expect($actual)->arrayNotToContainEqual($expected);
        expect($actual)->arrayNotToContainOnly($expected);
        expect($actual)->arrayNotToHaveCount($expected);
        expect($actual)->arrayNotToHaveKey($expected);
        expect($actual)->arrayNotToHaveSameSizeAs($expected);
        expect($actual)->arrayToContain($expected);
        expect($actual)->arrayToContainEqual($expected);
        expect($actual)->arrayToContainOnly($expected);
        expect($actual)->arrayToContainOnlyInstancesOf($expected);
        expect($actual)->arrayToHaveCount($expected);
        expect($actual)->arrayToHaveKey($expected);
        expect($actual)->arrayToHaveSameSizeAs($expected);
    }
}

?>
