<?php

namespace Package\Tests\Fixture;

use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function handlePasswordChange()
    {
        $this->assertEquals('3', '8', 'optional message');
        $this->assertTrue(true, 'assertion message');
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
        expect('8')->toEqual('3', 'optional message');
        expect(true)->toBeTrue('assertion message');
    }
}

?>
