<?php

namespace Package\Tests\Fixture;

use PHPUnit\Framework\TestCase;

class SomeClassTest extends TestCase
{
    public function handlePasswordChange()
    {
        $this->assertDirectoryIsNotReadable($directory);
        $this->assertDirectoryIsNotWritable($directory);
        $this->assertDirectoryDoesNotExist($directory);
        $this->assertDirectoryIsReadable($directory);
        $this->assertDirectoryIsWritable($directory);
        $this->assertDirectoryExists($directory);
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
        expect($directory)->directoryNotToBeReadable();
        expect($directory)->directoryNotToBeWritable();
        expect($directory)->directoryNotToExist();
        expect($directory)->directoryToBeReadable();
        expect($directory)->directoryToBeWritable();
        expect($directory)->directoryToExist();
    }
}

?>
