<?php
declare(strict_types=1);

namespace Tests\XpDevs\RectorVerify;

use PHPUnit\Framework\Attributes\DataProvider;
use Rector\Testing\PHPUnit\AbstractRectorTestCase;
use Symfony\Component\Finder\Finder;

class AssertionVerifyRectorTest extends AbstractRectorTestCase
{
    #[DataProvider('provideData')]
    public function test(string $filePath): void
    {
        $this->doTestFile($filePath);
    }

    public static function provideData(): \Iterator
    {
        $finder = (new Finder())->in(__DIR__.'/Fixture')->files()->name('*.php.inc')->sortByName();
        foreach ($finder as $fileInfo) {
            $testCaseName = substr($fileInfo->getRelativePathname(), 0, -8);
            (yield $testCaseName => [$fileInfo->getRealPath()]);
        }
    }

    public function provideConfigFilePath(): string
    {
        return __DIR__ . '/config/config.php';
    }
}
