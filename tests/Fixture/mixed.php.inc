<?php

namespace Package\Tests\Fixture;

use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function handlePasswordChange()
    {
        $this->assertIsNotClosedResource($actual);
        $this->assertIsClosedResource($actual);
        $this->assertNotEqualsCanonicalizing($expected, $actual);
        $this->assertNotEqualsIgnoringCase($expected, $actual);
        $this->assertNotEqualsWithDelta($expected, $actual, 0.1);
        $this->assertFinite($actual);
        $this->assertInfinite($actual);
        $this->assertNan($actual);
        $this->assertEqualsCanonicalizing($expected, $actual);
        $this->assertEqualsIgnoringCase($expected, $actual);
        $this->assertEqualsWithDelta($expected, $actual, 0.2);
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
        expect($actual)->notToBeClosedResource();
        expect($actual)->toBeClosedResource();
        expect($actual)->notToEqualCanonicalizing($expected);
        expect($actual)->notToEqualIgnoringCase($expected);
        $this->assertNotEqualsWithDelta($expected, $actual, 0.1);
        expect($actual)->toBeFinite();
        expect($actual)->toBeInfinite();
        expect($actual)->toBeNan();
        expect($actual)->toEqualCanonicalizing($expected);
        expect($actual)->toEqualIgnoringCase($expected);
        $this->assertEqualsWithDelta($expected, $actual, 0.2);
    }
}

?>
