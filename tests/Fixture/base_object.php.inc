<?php

namespace Package\Tests\Fixture;

use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function handlePasswordChange()
    {
        $this->assertObjectNotHasProperty('a', new \stdClass());
        $this->assertObjectHasProperty('b', new \stdClass());
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
        expect(new \stdClass())->baseObjectNotToHaveProperty('a');
        expect(new \stdClass())->baseObjectToHaveProperty('b');
    }
}

?>
