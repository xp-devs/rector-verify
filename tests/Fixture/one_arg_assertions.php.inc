<?php

namespace Package\Tests\Fixture;

use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function handlePasswordChange()
    {
        $actual = null;
        $this->assertTrue($actual);
        $this->assertNotTrue($actual);
        $this->assertFalse($actual);
        $this->assertNotFalse($actual);
        $this->assertNull($actual);
        $this->assertNotNull($actual);
        $this->assertEmpty($actual);
        $this->assertNotEmpty($actual);
        $this->assertIsArray($actual);
        $this->assertIsBool($actual);
        $this->assertIsFloat($actual);
        $this->assertIsInt($actual);
        $this->assertIsNumeric($actual);
        $this->assertIsObject($actual);
        $this->assertIsResource($actual);
        $this->assertIsString($actual);
        $this->assertIsScalar($actual);
        $this->assertIsCallable($actual);
        $this->assertIsIterable($actual);
        $this->assertIsNotArray($actual);
        $this->assertIsNotBool($actual);
        $this->assertIsNotFloat($actual);
        $this->assertIsNotInt($actual);
        $this->assertIsNotNumeric($actual);
        $this->assertIsNotObject($actual);
        $this->assertIsNotResource($actual);
        $this->assertIsNotString($actual);
        $this->assertIsNotScalar($actual);
        $this->assertIsNotCallable($actual);
        $this->assertIsNotIterable($actual);
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
        $actual = null;
        expect($actual)->toBeTrue();
        expect($actual)->notToBeTrue();
        expect($actual)->toBeFalse();
        expect($actual)->notToBeFalse();
        expect($actual)->toBeNull();
        expect($actual)->notToBeNull();
        expect($actual)->toBeEmpty();
        expect($actual)->notToBeEmpty();
        expect($actual)->toBeArray();
        expect($actual)->toBeBool();
        expect($actual)->toBeFloat();
        expect($actual)->toBeInt();
        expect($actual)->toBeNumeric();
        expect($actual)->toBeObject();
        expect($actual)->toBeResource();
        expect($actual)->toBeString();
        expect($actual)->toBeScalar();
        expect($actual)->toBeCallable();
        expect($actual)->toBeIterable();
        expect($actual)->notToBeArray();
        expect($actual)->notToBeBool();
        expect($actual)->notToBeFloat();
        expect($actual)->notToBeInt();
        expect($actual)->notToBeNumeric();
        expect($actual)->notToBeObject();
        expect($actual)->notToBeResource();
        expect($actual)->notToBeString();
        expect($actual)->notToBeScalar();
        expect($actual)->notToBeCallable();
        expect($actual)->notToBeIterable();
    }
}

?>
