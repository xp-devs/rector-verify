<?php

namespace Package\Tests\Rector\MyFirstRector\Fixture;

class SomeClassTest
{
    public function handlePasswordChange()
    {
        self::assertEquals('1', '2');
        $this->assertEquals('3', '8');
    }
}

?>

-----
<?php

namespace Package\Tests\Rector\MyFirstRector\Fixture;

class SomeClassTest
{
    public function handlePasswordChange()
    {
        self::assertEquals('1', '2');
        $this->assertEquals('3', '8');
    }
}

?>
