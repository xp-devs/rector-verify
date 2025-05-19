<?php

namespace Package\Tests\Fixture;

use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function __construct(private Bus $bus)
    {
    }

    public function handlePasswordChange()
    {
        $this->assertObjectNotHasProperty('a', new \stdClass());
        $this->assertObjectHasProperty('b', new \stdClass());
        $this->bus->assertCount(1);
    }
}

class Bus
{
    public function assertCount(int $count): void
    {

    }
}

?>

-----
<?php

namespace Package\Tests\Fixture;

use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function __construct(private Bus $bus)
    {
    }

    public function handlePasswordChange()
    {
        expect(new \stdClass())->baseObjectNotToHaveProperty('a');
        expect(new \stdClass())->baseObjectToHaveProperty('b');
        $this->bus->assertCount(1);
    }
}

class Bus
{
    public function assertCount(int $count): void
    {

    }
}

?>
