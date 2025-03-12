<?php

namespace Package\Tests\Rector\MyFirstRector\Fixture;

use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function handlePasswordChange()
    {
        self::assertEquals('1', '2');
    }
}

?>

-----
<?php

namespace Package\Tests\Rector\MyFirstRector\Fixture;

use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function handlePasswordChange()
    {
        expect('2')->toEqual('1');
    }
}

?>
