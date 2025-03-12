<?php

namespace Package\Tests\Fixture;

use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function handlePasswordChange()
    {
        $this->assertTrue(false);
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
        expect(false)->toBeTrue();
    }
}

?>
