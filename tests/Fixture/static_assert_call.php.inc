<?php

namespace Package\Tests\Fixture;

use PHPUnit\Framework\Assert;
use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function handlePasswordChange()
    {
        Assert::assertSame('test', 'actual');
    }
}

?>

-----
<?php

namespace Package\Tests\Fixture;

use PHPUnit\Framework\Assert;
use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function handlePasswordChange()
    {
        expect('actual')->toBe('test');
    }
}

?>
